
/*--------------------------------------------------------------------------------------------------------------
header file for the coordinator program
--------------------------------------------------------------------------------------------------------------*/

#include "coordinator.h"

/*--------------------------------------------------------------------------------------------------------------
header files included for different purposes
--------------------------------------------------------------------------------------------------------------*/

// for error reporting and diagnostics
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

// for math functions
#include <math.h>
#include <algorithm>
#include <climits>

// for tuple definitions found in the source code
#include "tuple.h"
#include <vector>

// for user defined functions found in the source code
#include "function.h"

// for LPU and PPU management data structures
#include "../../../common-libs/domain-obj/structure.h"
#include "../../src/runtime/common/lpu_management.h"

// for utility routines
#include "../../../common-libs/utils/list.h"
#include "../../../common-libs/utils/utility.h"
#include "../../../common-libs/utils/hashtable.h"
#include "../../../common-libs/utils/string_utils.h"
#include "../../../common-libs/utils/common_utils.h"
#include "../../../common-libs/utils/interval.h"
#include "../../../common-libs/utils/binary_search.h"
#include "../../../common-libs/utils/id_generation.h"

// for routines related to partition functions
#include "../../src/runtime/partition-lib/partition.h"
#include "../../src/runtime/partition-lib/index_xform.h"
#include "../../src/runtime/partition-lib/partition_mgmt.h"

// for memory management
#include "../../src/runtime/memory-management/allocation.h"
#include "../../src/runtime/memory-management/part_tracking.h"
#include "../../src/runtime/memory-management/part_generation.h"
#include "../../src/runtime/memory-management/part_management.h"

// for input-output
#include "../../src/runtime/file-io/stream.h"
#include "../../src/runtime/file-io/data_handler.h"

// for communication
#include "../../src/runtime/communication/part_folding.h"
#include "../../src/runtime/communication/part_config.h"
#include "../../src/runtime/communication/part_distribution.h"
#include "../../src/runtime/communication/confinement_mgmt.h"
#include "../../src/runtime/communication/data_transfer.h"
#include "../../src/runtime/communication/comm_buffer.h"
#include "../../src/runtime/communication/comm_statistics.h"
#include "../../src/runtime/communication/communicator.h"
#include "../../src/runtime/communication/scalar_communicator.h"
#include "../../src/runtime/communication/array_communicator.h"

// for task and program environment management and interaction
#include "../../src/runtime/environment/environment.h"
#include "../../src/runtime/environment/env_instruction.h"
#include "../../src/runtime/environment/array_transfer.h"

// for threading
#include <pthread.h>

// for MPI
#include <mpi.h>

// for synchronization
#include "../../src/runtime/common/sync.h"

// for reductions
#include "../../src/runtime/reduction/reduction_barrier.h"
#include "../../src/runtime/reduction/task_global_reduction.h"
#include "../../src/runtime/reduction/non_task_global_reduction.h"
#include "../../../common-libs/domain-obj/constant.h"

// for minimum and maximum values of numeric types
#include <limits.h>
#include <float.h>


/*--------------------------------------------------------------------------------------------------------------
header files for tasks
--------------------------------------------------------------------------------------------------------------*/

#include "lulesh.h"

/*--------------------------------------------------------------------------------------------------------------
function for reading program arguments
--------------------------------------------------------------------------------------------------------------*/

ProgramArgs readProgramArgs(int argc, char *argv[]) {

	ProgramArgs programArgs = ProgramArgs();

	for (int i = 1; i < argc; i++) {
		std::string keyValue = std::string(argv[i]);
		size_t separator = keyValue.find('=');
		if (separator == std::string::npos) {
			std::cout << "a command line parameter must be in the form of key=value\n";
			std::exit(EXIT_FAILURE);
		}
		std::string key = keyValue.substr(0, separator);
		std::string value = keyValue.substr(separator + 1);

		if (strcmp("iterations", key.c_str()) == 0) {
			std::istringstream stream(value);
			stream >> programArgs.iterations;
		} else if (strcmp("mesh_size", key.c_str()) == 0) {
			std::istringstream stream(value);
			stream >> programArgs.mesh_size;
		} else if (strcmp("output_file", key.c_str()) == 0) {
			programArgs.output_file = strdup(value.c_str());
		} else if (strcmp("p", key.c_str()) == 0) {
			std::istringstream stream(value);
			stream >> programArgs.p;
		} else {
			std::cout << "unrecognized command line parameter: " << key << '\n';
			std::exit(EXIT_FAILURE);
		}
	}
	return programArgs;
}

/*--------------------------------------------------------------------------------------------------------------
main function
--------------------------------------------------------------------------------------------------------------*/

int main(int argc, char *argv[]) {

	MPI_Init(&argc, &argv);

	// program environment management structure
	ProgramEnvironment *programEnv = new ProgramEnvironment();

	// task invocation index tracking variable
	int taskId = 0;

	// retreiving segmentation identifier
	int segmentId = 0;
	MPI_Comm_rank(MPI_COMM_WORLD, &segmentId);

	// starting execution timer clock
	struct timeval start;
	gettimeofday(&start, NULL);

	// creating a program log file
	std::ostringstream logFileName;
	logFileName << "segment_" << segmentId << ".log";
	std::ofstream logFile;
	logFile.open(logFileName.str().c_str());

	// reading command line inputs
	ProgramArgs args;
	args = readProgramArgs(argc, argv);

	// declaring local variables
	ll::TaskEnvironmentImpl *luleshEnv;

	//------------------------------------------ Coordinator Program

	luleshEnv = new ll::TaskEnvironmentImpl();
	luleshEnv->name = "LuLesh";
	luleshEnv->setProgramEnvironment(programEnv);
	luleshEnv->setLogFile(&logFile);
	{ // scope starts for invoking: LuLesh
	logFile << "going to execute task: LuLesh\n";
	logFile.flush();
	luleshEnv->setupItemsDimensions();
	luleshEnv->setTaskId(taskId);
	taskId++;
	LLPartition partition;
	partition.p = args.p;
	ll::execute(luleshEnv, args.mesh_size, args.iterations, partition, segmentId, logFile);
	luleshEnv->resetEnvInstructions();
	} // scope ends for task invocation
	luleshEnv->writeItemToFile("output", args.output_file);

	//--------------------------------------------------------------

	// calculating task running time
	struct timeval end;
	gettimeofday(&end, NULL);
	double runningTime = ((end.tv_sec + end.tv_usec / 1000000.0)
			- (start.tv_sec + start.tv_usec / 1000000.0));
	logFile << "Execution Time: " << runningTime << " Seconds" << std::endl;
	logFile.flush();

	logFile.close();
	std::cout << "Parallel Execution Time: " << runningTime << " Seconds" << std::endl;
	MPI_Finalize();
	return 0;
}

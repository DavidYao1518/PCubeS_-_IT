#ifndef _H_ll
#define _H_ll

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


namespace ll {


/*--------------------------------------------------------------------------------------------------------------
processor ordering in the hardware
--------------------------------------------------------------------------------------------------------------*/

const int Processor_Order[64] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9
		, 10, 11, 12, 13, 14, 15, 32, 33, 34, 35
		, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45
		, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55
		, 56, 57, 58, 59, 60, 61, 62, 63, 16, 17
		, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

/*--------------------------------------------------------------------------------------------------------------
constants for LPSes
--------------------------------------------------------------------------------------------------------------*/

const int Space_Root = 0;
const int Space_A = 1;
const int Space_B = 2;
const int Space_Count = 3;

/*--------------------------------------------------------------------------------------------------------------
constants for PPS counts
--------------------------------------------------------------------------------------------------------------*/

const int Space_6_PPUs = 1;
const int Space_5_Par_6_PPUs = 4;
const int Space_4_Par_5_PPUs = 4;
const int Space_3_Par_4_PPUs = 2;
const int Space_2_Par_3_PPUs = 4;
const int Space_1_Par_2_PPUs = 2;

/*--------------------------------------------------------------------------------------------------------------
thread count constants
--------------------------------------------------------------------------------------------------------------*/

//----------------------------------------------------------------------------------------------System Constants
const int Max_Space_Root_Threads = 1;
const int Max_Space_A_Threads = 1;
const int Max_Space_B_Threads = 64;
const int Max_Total_Threads = 64;
static int Total_Threads = 64;

//---------------------------------------------------------------------------------------------Segment Constants
const int Threads_Per_Segment = 64;
const int Max_Segments_Count = 1;
const int Space_Root_Threads_Per_Segment = 1;
const int Space_A_Threads_Per_Segment = 1;
const int Space_B_Threads_Per_Segment = 64;

//--------------------------------------------------------------------------------------------Hardware Constants
const int Threads_Per_Core = 1;
const int Processors_Per_Phy_Unit = 64;
const int Core_Jump = 1;

/*--------------------------------------------------------------------------------------------------------------
Data structures for Array-Metadata and Environment-Links
--------------------------------------------------------------------------------------------------------------*/

class ArrayMetadata : public Metadata {
  public:
	Dimension elementsDims[3];
	Dimension nodesDims[3];
	Dimension outputDims[3];

	ArrayMetadata();
	void print(std::ofstream &stream);
};
static ArrayMetadata arrayMetadata;

class EnvironmentLinks {
  public:

	void print(std::ofstream &stream);
};
static EnvironmentLinks environmentLinks;


/*--------------------------------------------------------------------------------------------------------------
data structures representing LPUs
--------------------------------------------------------------------------------------------------------------*/

//----------------------------------------------------------------------------------------------------Space Root
class SpaceRoot_LPU : public LPU {
  public:
	Element *elements;
	PartDimension elementsPartDims[3];
	Node *nodes;
	PartDimension nodesPartDims[3];
	double *output;
	PartDimension outputPartDims[3];

	void print(std::ofstream &stream, int indent);
};

//-------------------------------------------------------------------------------------------------------Space A
class SpaceA_LPU : public LPU {
  public:
	Element *elements;
	PartDimension elementsPartDims[3];
	Node *nodes;
	PartDimension nodesPartDims[3];
	double *output;
	PartDimension outputPartDims[3];

	void print(std::ofstream &stream, int indent);
};

//-------------------------------------------------------------------------------------------------------Space B
class SpaceB_LPU : public LPU {
  public:
	Element *elements;
	PartDimension elementsPartDims[3];
	Node *nodes;
	PartDimension nodesPartDims[3];
	double *output;
	PartDimension outputPartDims[3];
	int lpuId[1];

	void print(std::ofstream &stream, int indent);
};

/*--------------------------------------------------------------------------------------------------------------
Data structures for Task-Global and Thread-Local scalar variables
--------------------------------------------------------------------------------------------------------------*/

class TaskGlobals {
  public:
	int counter_1;
	int counter_2;
	int counter_3;
	double deltaTime;
	int element_size;
	double hgcoef;
	int max_iterations;
	int node_size;
	double stopTime;
};

class ThreadLocals {
  public:
};

/*--------------------------------------------------------------------------------------------------------------
functions for generating partition configuration objects for data structures
--------------------------------------------------------------------------------------------------------------*/

//-------------------------------------------------------------------------------------------------------Space A
DataPartitionConfig *getelementsConfigForSpaceA(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap);
DataPartitionConfig *getnodesConfigForSpaceA(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap);
DataPartitionConfig *getoutputConfigForSpaceA(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap);

//-------------------------------------------------------------------------------------------------------Space B
DataPartitionConfig *getelementsConfigForSpaceB(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap);
DataPartitionConfig *getnodesConfigForSpaceB(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap);
DataPartitionConfig *getoutputConfigForSpaceB(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap);

//---------------------------------------------------------------------------Partition Configuration Accumulator
Hashtable<DataPartitionConfig*> *getDataPartitionConfigMap(ArrayMetadata *metadata, 
		LLPartition partition, int *ppuCounts);


/*--------------------------------------------------------------------------------------------------------------
functions for generating memory blocks for data parts of various LPUs
--------------------------------------------------------------------------------------------------------------*/

LpsContent *genSpaceBContent(List<ThreadState*> *threads, ArrayMetadata *metadata, 
		TaskEnvironment *environment, 
		LLPartition partition, 
		Hashtable<DataPartitionConfig*> *partConfigMap);

//-----------------------------------------------------------------------------------------Task Data Initializer
TaskData *initializeTaskData(List<ThreadState*> *threads, ArrayMetadata *metadata, 
		TaskEnvironment *environment, 
		SegmentState *segment, 
		LLPartition partition, int *ppuCounts);


/*--------------------------------------------------------------------------------------------------------------
data structure spacific part reader and writer subclasses
--------------------------------------------------------------------------------------------------------------*/

//-------------------------------------------------------------------------------------------------------Space B

class outputInSpaceBReader : public PartReader {
  protected:
	TypedInputStream<double> *stream;
  public:
	outputInSpaceBReader(DataPartitionConfig *partConfig, DataPartsList *partsList)
			: PartReader(partsList, partConfig) {
		this->partConfig = partConfig;
		this->stream = NULL;
	}
	void begin() {
		stream = new TypedInputStream<double>(fileName);
		Assert(stream != NULL);
		stream->open();
	}
	void terminate() {
		stream->close();
		delete stream;
	}
	List<int> *getDataIndex(List<int> *partIndex) { return partIndex; }
	void readElement(List<int> *dataIndex, long int storeIndex, void *partStore) {
		double *dataStore = (double*) partStore;
		dataStore[storeIndex] = stream->readElement(dataIndex);
	}
};

class outputInSpaceBWriter : public PartWriter {
  protected:
	TypedOutputStream<double> *stream;
  public:
	outputInSpaceBWriter(DataPartitionConfig *partConfig, int writerId, DataPartsList *partsList)
			: PartWriter(writerId, partsList, partConfig) {
		this->partConfig = partConfig;
		this->stream = NULL;
	}
	void begin() {
		stream = new TypedOutputStream<double>(fileName, getDimensionList(), writerId == 0);
		Assert(stream != NULL);
		stream->open();
	}
	void terminate() {
		stream->close();
		delete stream;
	}
	List<int> *getDataIndex(List<int> *partIndex) { return partIndex; }
	void writeElement(List<int> *dataIndex, long int storeIndex, void *partStore) {
		double *dataStore = (double*) partStore;
		stream->writeElement(dataStore[storeIndex], dataIndex);
	}
};

/*--------------------------------------------------------------------------------------------------------------
file I/O for environmental data structures
--------------------------------------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------------Parts-reader map generator
Hashtable<PartReader*> *generateReadersMap(TaskData *taskData, 
			SegmentState *segment, 
			Hashtable<DataPartitionConfig*> *partConfigMap);

//------------------------------------------------------------------------------------Parts-writer map generator
Hashtable<PartWriter*> *generateWritersMap(TaskData *taskData, 
			SegmentState *segment, 
			Hashtable<DataPartitionConfig*> *partConfigMap);

/*--------------------------------------------------------------------------------------------------------------
functions for retrieving partition counts in different LPSes
--------------------------------------------------------------------------------------------------------------*/

int *getLPUsCountOfSpaceB(Hashtable<DataPartitionConfig*> *partConfigMap);

/*--------------------------------------------------------------------------------------------------------------
functions for generating LPUs given LPU Ids
--------------------------------------------------------------------------------------------------------------*/

void generateSpaceALpu(ThreadState *threadState, 
			Hashtable<DataPartitionConfig*> *partConfigMap, 
			TaskData *taskData);
void generateSpaceBLpu(ThreadState *threadState, 
			Hashtable<DataPartitionConfig*> *partConfigMap, 
			TaskData *taskData);

/*--------------------------------------------------------------------------------------------------------------
functions to generate PPU IDs and PPU group IDs for a thread
--------------------------------------------------------------------------------------------------------------*/

ThreadIds *getPpuIdsForThread(int threadNo);

void adjustPpuCountsAndGroupSizes(ThreadIds *threadId);


/*--------------------------------------------------------------------------------------------------------------
Thread-State implementation class for the task
--------------------------------------------------------------------------------------------------------------*/

class ThreadStateImpl : public ThreadState {
  public:
	ThreadStateImpl(int lpsCount, int *lpsDimensions, 
			int *partitionArgs, 
			ThreadIds *threadIds) 
		: ThreadState(lpsCount, lpsDimensions, partitionArgs, threadIds) {}
	void setLpsParentIndexMap();
        void setRootLpu(Metadata *metadata);
        void setRootLpu(LPU *rootLpu);
	void initializeLPUs();
        int *computeLpuCounts(int lpsId);
        LPU *computeNextLpu(int lpsId);
	void initializeReductionResultMap();
};


/*--------------------------------------------------------------------------------------------------------------
Task Environment Management Structures and Functions
--------------------------------------------------------------------------------------------------------------*/

//-------------------------------------------------------------------------Task Environment Implementation Class

class TaskEnvironmentImpl : public TaskEnvironment {
  public:
	TaskEnvironmentImpl();
	void prepareItemsMap();
	void setDefaultTaskCompletionInstrs();
};

//--------------------------------------------------------------------------Environmental Links Object Generator

EnvironmentLinks initiateEnvLinks(TaskEnvironment *environment);

//---------------------------------------------------------------------------------LPS Allocation Preconfigurers

void preconfigureLpsAllocationsInEnv(TaskEnvironment *environment, 
		ArrayMetadata *metadata, 
		Hashtable<DataPartitionConfig*> *partConfigMap);

//------------------------------------------------------------------------------------Non-array variables copier

void copyBackNonArrayEnvVariables(TaskEnvironment *environment, TaskGlobals *taskGlobals);

/*--------------------------------------------------------------------------------------------------------------
task executor function
--------------------------------------------------------------------------------------------------------------*/

void execute(TaskEnvironment *environment, 
		int mesh_size, 
		int iterations, 
		LLPartition partition, 
		int segmentId, 
		std::ofstream &logFile);

/*--------------------------------------------------------------------------------------------------------------
function for the initialize block
--------------------------------------------------------------------------------------------------------------*/

void initializeTask(ArrayMetadata *arrayMetadata, 
		EnvironmentLinks environmentLinks, 
		TaskGlobals *taskGlobals, 
		ThreadLocals *threadLocals, 
		LLPartition partition, 
		int mesh_size, 
		int iterations);


/*--------------------------------------------------------------------------------------------------------------
functions for compute stages
--------------------------------------------------------------------------------------------------------------*/

int calcelemshapefunctionderivatives_stage_3(SpaceB_LPU *lpu, 
		ArrayMetadata *arrayMetadata, 
		TaskGlobals *taskGlobals, 
		ThreadLocals *threadLocals, 
		LLPartition partition, 
		std::ofstream &logFile);


/*--------------------------------------------------------------------------------------------------------------
run method for thread simulating the task flow
--------------------------------------------------------------------------------------------------------------*/

void run(ArrayMetadata *arrayMetadata, 
		TaskGlobals *taskGlobals, 
		ThreadLocals *threadLocals, 
		LLPartition partition, ThreadStateImpl *threadState);

/*-----------------------------------------------------------------------------------
Data structure and function for Pthreads
------------------------------------------------------------------------------------*/

class PThreadArg {
  public:
	const char *taskName;
	ArrayMetadata *metadata;
	TaskGlobals *taskGlobals;
	ThreadLocals *threadLocals;
	LLPartition partition;
	ThreadStateImpl *threadState;
};

void *runPThreads(void *argument);

}
#endif

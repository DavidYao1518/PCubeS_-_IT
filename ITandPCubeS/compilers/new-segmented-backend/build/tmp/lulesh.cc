
/*--------------------------------------------------------------------------------------------------------------
header file for the task
--------------------------------------------------------------------------------------------------------------*/
#include "lulesh.h"


/*--------------------------------------------------------------------------------------------------------------
header files for different purposes
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


using namespace ll;


/*--------------------------------------------------------------------------------------------------------------
Functions for ArrayMetadata and EnvironmentLinks
--------------------------------------------------------------------------------------------------------------*/

ll::ArrayMetadata::ArrayMetadata() : Metadata() {
	setTaskName("LuLesh");
}

void ll::ArrayMetadata::print(std::ofstream &stream) {
	stream << "Array Metadata" << std::endl;
	stream << "Array: elements";
	stream << ' ';
	elementsDims[0].print(stream);
	stream << ' ';
	elementsDims[1].print(stream);
	stream << ' ';
	elementsDims[2].print(stream);
	stream << std::endl;
	stream << "Array: nodes";
	stream << ' ';
	nodesDims[0].print(stream);
	stream << ' ';
	nodesDims[1].print(stream);
	stream << ' ';
	nodesDims[2].print(stream);
	stream << std::endl;
	stream << "Array: output";
	stream << ' ';
	outputDims[0].print(stream);
	stream << ' ';
	outputDims[1].print(stream);
	stream << ' ';
	outputDims[2].print(stream);
	stream << std::endl;
	stream.flush();
}

/*--------------------------------------------------------------------------------------------------------------
LPU print functions
--------------------------------------------------------------------------------------------------------------*/

void ll::SpaceRoot_LPU::print(std::ofstream &stream, int indentLevel) {
	for (int i = 0; i < indentLevel; i++) stream << '\t';
	stream << "Array: elements" << std::endl;
	elementsPartDims[0].print(stream, indentLevel + 1);
	elementsPartDims[1].print(stream, indentLevel + 1);
	elementsPartDims[2].print(stream, indentLevel + 1);
	for (int i = 0; i < indentLevel; i++) stream << '\t';
	stream << "Array: nodes" << std::endl;
	nodesPartDims[0].print(stream, indentLevel + 1);
	nodesPartDims[1].print(stream, indentLevel + 1);
	nodesPartDims[2].print(stream, indentLevel + 1);
	for (int i = 0; i < indentLevel; i++) stream << '\t';
	stream << "Array: output" << std::endl;
	outputPartDims[0].print(stream, indentLevel + 1);
	outputPartDims[1].print(stream, indentLevel + 1);
	outputPartDims[2].print(stream, indentLevel + 1);
	stream.flush();
}

void ll::SpaceA_LPU::print(std::ofstream &stream, int indentLevel) {
	for (int i = 0; i < indentLevel; i++) stream << '\t';
	stream << "Array: elements" << std::endl;
	elementsPartDims[0].print(stream, indentLevel + 1);
	elementsPartDims[1].print(stream, indentLevel + 1);
	elementsPartDims[2].print(stream, indentLevel + 1);
	for (int i = 0; i < indentLevel; i++) stream << '\t';
	stream << "Array: nodes" << std::endl;
	nodesPartDims[0].print(stream, indentLevel + 1);
	nodesPartDims[1].print(stream, indentLevel + 1);
	nodesPartDims[2].print(stream, indentLevel + 1);
	for (int i = 0; i < indentLevel; i++) stream << '\t';
	stream << "Array: output" << std::endl;
	outputPartDims[0].print(stream, indentLevel + 1);
	outputPartDims[1].print(stream, indentLevel + 1);
	outputPartDims[2].print(stream, indentLevel + 1);
	stream.flush();
}

void ll::SpaceB_LPU::print(std::ofstream &stream, int indentLevel) {
	for (int i = 0; i < indentLevel; i++) stream << '\t';
	stream << "Array: elements" << std::endl;
	elementsPartDims[0].print(stream, indentLevel + 1);
	elementsPartDims[1].print(stream, indentLevel + 1);
	elementsPartDims[2].print(stream, indentLevel + 1);
	for (int i = 0; i < indentLevel; i++) stream << '\t';
	stream << "Array: nodes" << std::endl;
	nodesPartDims[0].print(stream, indentLevel + 1);
	nodesPartDims[1].print(stream, indentLevel + 1);
	nodesPartDims[2].print(stream, indentLevel + 1);
	for (int i = 0; i < indentLevel; i++) stream << '\t';
	stream << "Array: output" << std::endl;
	outputPartDims[0].print(stream, indentLevel + 1);
	outputPartDims[1].print(stream, indentLevel + 1);
	outputPartDims[2].print(stream, indentLevel + 1);
	stream.flush();
}


/*--------------------------------------------------------------------------------------------------------------
functions for generating partition configuration objects for data structures
--------------------------------------------------------------------------------------------------------------*/

//-------------------------------------------------------------------------------------------------------Space A

DataPartitionConfig *ll::getelementsConfigForSpaceA(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap) {
	List<DimPartitionConfig*> *dimensionConfigs = new List<DimPartitionConfig*>;
	Assert(dimensionConfigs != NULL);
	dimensionConfigs->Append(new ReplicationConfig(metadata->elementsDims[0]));
	dimensionConfigs->Append(new ReplicationConfig(metadata->elementsDims[1]));
	dimensionConfigs->Append(new ReplicationConfig(metadata->elementsDims[2]));
	DataPartitionConfig *config =  new DataPartitionConfig(3, dimensionConfigs);
	config->configureDimensionOrder();
	config->setLpsId(Space_A);
	return config;
}

DataPartitionConfig *ll::getnodesConfigForSpaceA(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap) {
	List<DimPartitionConfig*> *dimensionConfigs = new List<DimPartitionConfig*>;
	Assert(dimensionConfigs != NULL);
	dimensionConfigs->Append(new ReplicationConfig(metadata->nodesDims[0]));
	dimensionConfigs->Append(new ReplicationConfig(metadata->nodesDims[1]));
	dimensionConfigs->Append(new ReplicationConfig(metadata->nodesDims[2]));
	DataPartitionConfig *config =  new DataPartitionConfig(3, dimensionConfigs);
	config->configureDimensionOrder();
	config->setLpsId(Space_A);
	return config;
}

DataPartitionConfig *ll::getoutputConfigForSpaceA(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap) {
	List<DimPartitionConfig*> *dimensionConfigs = new List<DimPartitionConfig*>;
	Assert(dimensionConfigs != NULL);
	dimensionConfigs->Append(new ReplicationConfig(metadata->outputDims[0]));
	dimensionConfigs->Append(new ReplicationConfig(metadata->outputDims[1]));
	dimensionConfigs->Append(new ReplicationConfig(metadata->outputDims[2]));
	DataPartitionConfig *config =  new DataPartitionConfig(3, dimensionConfigs);
	config->configureDimensionOrder();
	config->setLpsId(Space_A);
	return config;
}

//-------------------------------------------------------------------------------------------------------Space B

DataPartitionConfig *ll::getelementsConfigForSpaceB(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap) {
	List<DimPartitionConfig*> *dimensionConfigs = new List<DimPartitionConfig*>;
	Assert(dimensionConfigs != NULL);
	int *dim0Paddings = new int[2];
	dim0Paddings[0] = 0;
	dim0Paddings[1] = 0;
	int *dim0Arguments = new int;
	dim0Arguments[0] = partition.p;
	dimensionConfigs->Append(new BlockCountConfig(metadata->elementsDims[0], 
			dim0Arguments, dim0Paddings, ppuCount, 0));
	delete[] dim0Paddings;
	dimensionConfigs->Append(new ReplicationConfig(metadata->elementsDims[1]));
	dimensionConfigs->Append(new ReplicationConfig(metadata->elementsDims[2]));
	DataPartitionConfig *config =  new DataPartitionConfig(3, dimensionConfigs);
	config->setParent(configMap->Lookup("elementsSpaceAConfig"), 1);
	config->configureDimensionOrder();
	config->setLpsId(Space_B);
	return config;
}

DataPartitionConfig *ll::getnodesConfigForSpaceB(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap) {
	List<DimPartitionConfig*> *dimensionConfigs = new List<DimPartitionConfig*>;
	Assert(dimensionConfigs != NULL);
	int *dim0Paddings = new int[2];
	dim0Paddings[0] = 0;
	dim0Paddings[1] = 0;
	int *dim0Arguments = new int;
	dim0Arguments[0] = partition.p;
	dimensionConfigs->Append(new BlockCountConfig(metadata->nodesDims[0], 
			dim0Arguments, dim0Paddings, ppuCount, 0));
	delete[] dim0Paddings;
	dimensionConfigs->Append(new ReplicationConfig(metadata->nodesDims[1]));
	dimensionConfigs->Append(new ReplicationConfig(metadata->nodesDims[2]));
	DataPartitionConfig *config =  new DataPartitionConfig(3, dimensionConfigs);
	config->setParent(configMap->Lookup("nodesSpaceAConfig"), 1);
	config->configureDimensionOrder();
	config->setLpsId(Space_B);
	return config;
}

DataPartitionConfig *ll::getoutputConfigForSpaceB(ArrayMetadata *metadata, 
		LLPartition partition, 
		int ppuCount, 
		Hashtable<DataPartitionConfig*> *configMap) {
	List<DimPartitionConfig*> *dimensionConfigs = new List<DimPartitionConfig*>;
	Assert(dimensionConfigs != NULL);
	int *dim0Paddings = new int[2];
	dim0Paddings[0] = 0;
	dim0Paddings[1] = 0;
	int *dim0Arguments = new int;
	dim0Arguments[0] = partition.p;
	dimensionConfigs->Append(new BlockCountConfig(metadata->outputDims[0], 
			dim0Arguments, dim0Paddings, ppuCount, 0));
	delete[] dim0Paddings;
	dimensionConfigs->Append(new ReplicationConfig(metadata->outputDims[1]));
	dimensionConfigs->Append(new ReplicationConfig(metadata->outputDims[2]));
	DataPartitionConfig *config =  new DataPartitionConfig(3, dimensionConfigs);
	config->setParent(configMap->Lookup("outputSpaceAConfig"), 1);
	config->configureDimensionOrder();
	config->setLpsId(Space_B);
	return config;
}

//---------------------------------------------------------------------------Partition Configuration Accumulator

Hashtable<DataPartitionConfig*> *ll::getDataPartitionConfigMap(ArrayMetadata *metadata, 
		LLPartition partition, int *ppuCounts) {
	Hashtable<DataPartitionConfig*> *configMap = new Hashtable<DataPartitionConfig*>;
	DataPartitionConfig *elementsSpaceAConfig = getelementsConfigForSpaceA(metadata, 
		partition, ppuCounts[Space_A], configMap);
	configMap->Enter("elementsSpaceAConfig", elementsSpaceAConfig);
	DataPartitionConfig *nodesSpaceAConfig = getnodesConfigForSpaceA(metadata, 
		partition, ppuCounts[Space_A], configMap);
	configMap->Enter("nodesSpaceAConfig", nodesSpaceAConfig);
	DataPartitionConfig *outputSpaceAConfig = getoutputConfigForSpaceA(metadata, 
		partition, ppuCounts[Space_A], configMap);
	configMap->Enter("outputSpaceAConfig", outputSpaceAConfig);
	DataPartitionConfig *elementsSpaceBConfig = getelementsConfigForSpaceB(metadata, 
		partition, ppuCounts[Space_B], configMap);
	configMap->Enter("elementsSpaceBConfig", elementsSpaceBConfig);
	DataPartitionConfig *nodesSpaceBConfig = getnodesConfigForSpaceB(metadata, 
		partition, ppuCounts[Space_B], configMap);
	configMap->Enter("nodesSpaceBConfig", nodesSpaceBConfig);
	DataPartitionConfig *outputSpaceBConfig = getoutputConfigForSpaceB(metadata, 
		partition, ppuCounts[Space_B], configMap);
	configMap->Enter("outputSpaceBConfig", outputSpaceBConfig);
	return configMap;
}

/*--------------------------------------------------------------------------------------------------------------
functions for generating memory blocks for data parts of various LPUs
--------------------------------------------------------------------------------------------------------------*/

LpsContent *ll::genSpaceBContent(List<ThreadState*> *threads, ArrayMetadata *metadata, 
		TaskEnvironment *environment, 
		LLPartition partition, 
		Hashtable<DataPartitionConfig*> *partConfigMap) {

	if(threads->NumElements() == 0) return NULL;
	LpsContent *spaceBContent = new LpsContent(Space_B);

	DataItems *elements = new DataItems("elements", 3, true);
	DataPartitionConfig *elementsConfig = partConfigMap->Lookup("elementsSpaceBConfig");
	elements->setPartitionConfig(elementsConfig);
	DataPartsList *elementsParts = elementsConfig->generatePartList(1);
	elements->setPartsList(elementsParts);
	std::vector<DimConfig> elementsDimOrder = *(elementsConfig->getDimensionOrder());
	PartIdContainer *elementsContainer = NULL;
	if (elementsDimOrder.size() == 1) elementsContainer = new PartContainer(elementsDimOrder[0]);
	else elementsContainer = new PartListContainer(elementsDimOrder[0]);
	Assert(elementsContainer != NULL);
	List<int*> *elementsPartId = elementsConfig->generatePartIdTemplate();
	spaceBContent->addDataItems("elements", elements);

	DataItems *nodes = new DataItems("nodes", 3, true);
	DataPartitionConfig *nodesConfig = partConfigMap->Lookup("nodesSpaceBConfig");
	nodes->setPartitionConfig(nodesConfig);
	DataPartsList *nodesParts = nodesConfig->generatePartList(1);
	nodes->setPartsList(nodesParts);
	std::vector<DimConfig> nodesDimOrder = *(nodesConfig->getDimensionOrder());
	PartIdContainer *nodesContainer = NULL;
	if (nodesDimOrder.size() == 1) nodesContainer = new PartContainer(nodesDimOrder[0]);
	else nodesContainer = new PartListContainer(nodesDimOrder[0]);
	Assert(nodesContainer != NULL);
	List<int*> *nodesPartId = nodesConfig->generatePartIdTemplate();
	spaceBContent->addDataItems("nodes", nodes);

	DataItems *output = new DataItems("output", 3, false);
	DataPartitionConfig *outputConfig = partConfigMap->Lookup("outputSpaceBConfig");
	output->setPartitionConfig(outputConfig);
	DataPartsList *outputParts = outputConfig->generatePartList(1);
	output->setPartsList(outputParts);
	std::vector<DimConfig> outputDimOrder = *(outputConfig->getDimensionOrder());
	PartIdContainer *outputContainer = NULL;
	if (outputDimOrder.size() == 1) outputContainer = new PartContainer(outputDimOrder[0]);
	else outputContainer = new PartListContainer(outputDimOrder[0]);
	Assert(outputContainer != NULL);
	List<int*> *outputPartId = outputConfig->generatePartIdTemplate();
	spaceBContent->addDataItems("output", output);

	for (int i = 0; i < threads->NumElements(); i++) {
		ThreadState *thread = threads->Nth(i);
		int lpuId = INVALID_ID;
		while((lpuId = thread->getNextLpuId(Space_B, Space_Root, lpuId)) != INVALID_ID) {
			List<int*> *lpuIdChain = thread->getLpuIdChainWithoutCopy(
					Space_B, Space_Root);
			elementsConfig->generatePartId(lpuIdChain, elementsPartId);
			elementsContainer->insertPartId(elementsPartId, 3, elementsDimOrder);
			nodesConfig->generatePartId(lpuIdChain, nodesPartId);
			nodesContainer->insertPartId(nodesPartId, 3, nodesDimOrder);
			outputConfig->generatePartId(lpuIdChain, outputPartId);
			outputContainer->insertPartId(outputPartId, 3, outputDimOrder);
		}
	}

	elementsParts->initializePartsList(elementsConfig, elementsContainer, sizeof(Element));
	elementsParts->allocateParts();

	nodesParts->initializePartsList(nodesConfig, nodesContainer, sizeof(Node));
	nodesParts->allocateParts();

	outputParts->initializePartsList(outputConfig, outputContainer, sizeof(double));
	TaskItem *outputItem = environment->getItem("output");
	LpsAllocation *outputAlloc = outputItem->getLpsAllocation("B");
	outputAlloc->setPartContainerTree(outputContainer);
	outputAlloc->setPartsList(new PartsList(outputParts->getPartList()));

	return spaceBContent;
}

//-----------------------------------------------------------------------------------------Task Data Initializer

TaskData *ll::initializeTaskData(List<ThreadState*> *threads, ArrayMetadata *metadata, 
		TaskEnvironment *environment, 
		SegmentState *segment, 
		LLPartition partition, int *ppuCounts) {

	Hashtable<DataPartitionConfig*> *configMap = 
			getDataPartitionConfigMap(metadata, partition, ppuCounts);
	TaskData *taskData = new TaskData();
	Assert(taskData != NULL);
	preconfigureLpsAllocationsInEnv(environment, metadata, configMap);

	// prepare LPS contents map
	LpsContent *spaceBContent = genSpaceBContent(threads, metadata, 
			environment, partition, configMap);
	taskData->addLpsContent("B", spaceBContent);

	// prepare file I/O handlers in the environment
	Hashtable<PartReader*> *readersMap = generateReadersMap(taskData, segment, configMap);
	environment->setReadersMap(readersMap);
	Hashtable<PartWriter*> *writersMap = generateWritersMap(taskData, segment, configMap);
	environment->setWritersMap(writersMap);

	// initialize parts lists of environmental variables
	environment->preprocessProgramEnvForItems();
	environment->setupItemsPartsLists();
	environment->postprocessProgramEnvForItems();
	return taskData;
}

/*--------------------------------------------------------------------------------------------------------------
file I/O for environmental data structures
--------------------------------------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------------Parts-reader map generator
Hashtable<PartReader*> *ll::generateReadersMap(TaskData *taskData, 
			SegmentState *segment, 
			Hashtable<DataPartitionConfig*> *partConfigMap) {

	Hashtable<PartReader*> *readersMap = new Hashtable<PartReader*>;

	// readers for Space B
	DataItems *outputInSpaceB = taskData->getDataItemsOfLps("B", "output");
	if (outputInSpaceB != NULL && !outputInSpaceB->isEmpty()) {
		DataPartitionConfig *config = partConfigMap->Lookup("outputSpaceBConfig");
		outputInSpaceBReader *reader = new outputInSpaceBReader(config, outputInSpaceB->getPartsList());
		Assert(reader != NULL);
		readersMap->Enter("outputInSpaceBReader", reader);
	} else {
		readersMap->Enter("outputInSpaceBReader", NULL);
	}

	return readersMap;
}

//------------------------------------------------------------------------------------Parts-writer map generator
Hashtable<PartWriter*> *ll::generateWritersMap(TaskData *taskData, 
			SegmentState *segment, 
			Hashtable<DataPartitionConfig*> *partConfigMap) {

	Hashtable<PartWriter*> *writersMap = new Hashtable<PartWriter*>;

	int writerId;
	MPI_Comm_rank(MPI_COMM_WORLD, &writerId);
	int mpiProcessCount;
	MPI_Comm_size(MPI_COMM_WORLD, &mpiProcessCount);
	int writersCount = min(mpiProcessCount, Max_Segments_Count);

	// writers for Space B
	DataItems *outputInSpaceB = taskData->getDataItemsOfLps("B", "output");
	if (outputInSpaceB != NULL && !outputInSpaceB->isEmpty() && segment->computeStagesInLps(Space_B)) {
		DataPartitionConfig *config = partConfigMap->Lookup("outputSpaceBConfig");
		outputInSpaceBWriter *writer = new outputInSpaceBWriter(config, 
				writerId, outputInSpaceB->getPartsList());
		Assert(writer != NULL);
		writer->setWritersCount(writersCount);
		writersMap->Enter("outputInSpaceBWriter", writer);
	} else {
		writersMap->Enter("outputInSpaceBWriter", NULL);
	}

	return writersMap;
}

/*--------------------------------------------------------------------------------------------------------------
functions for retrieving partition counts in different LPSes
--------------------------------------------------------------------------------------------------------------*/

int *ll::getLPUsCountOfSpaceB(Hashtable<DataPartitionConfig*> *partConfigMap) {
	int *count = new int[1];
	DataPartitionConfig *nodesConfig = partConfigMap->Lookup("nodesSpaceBConfig");
	count[0] = nodesConfig->getPartsCountAlongDimension(0);
	return count;
}

/*--------------------------------------------------------------------------------------------------------------
functions for generating LPUs given LPU Ids
--------------------------------------------------------------------------------------------------------------*/

void ll::generateSpaceALpu(ThreadState *threadState, 
			Hashtable<DataPartitionConfig*> *partConfigMap, 
			TaskData *taskData) {

	int *lpuId = threadState->getCurrentLpuId(Space_A);
	int *lpuCounts = threadState->getLpuCounts(Space_A);
	SpaceA_LPU *lpu = (SpaceA_LPU*) threadState->getCurrentLpu(Space_A, true);
	List<int*> *lpuIdChain = threadState->getLpuIdChainWithoutCopy(Space_A, Space_Root);

	DataPartitionConfig *elementsConfig = partConfigMap->Lookup("elementsSpaceAConfig");
	SpaceRoot_LPU *spaceRootLpu = (SpaceRoot_LPU*) threadState->getCurrentLpu(Space_Root);
	PartDimension *elementsParentPartDims = spaceRootLpu->elementsPartDims;
	elementsConfig->updatePartDimensionInfo(lpuId, lpuCounts, lpu->elementsPartDims, elementsParentPartDims);

	DataPartitionConfig *nodesConfig = partConfigMap->Lookup("nodesSpaceAConfig");
	PartDimension *nodesParentPartDims = spaceRootLpu->nodesPartDims;
	nodesConfig->updatePartDimensionInfo(lpuId, lpuCounts, lpu->nodesPartDims, nodesParentPartDims);

	DataPartitionConfig *outputConfig = partConfigMap->Lookup("outputSpaceAConfig");
	PartDimension *outputParentPartDims = spaceRootLpu->outputPartDims;
	outputConfig->updatePartDimensionInfo(lpuId, lpuCounts, lpu->outputPartDims, outputParentPartDims);
}

void ll::generateSpaceBLpu(ThreadState *threadState, 
			Hashtable<DataPartitionConfig*> *partConfigMap, 
			TaskData *taskData) {

	int *lpuId = threadState->getCurrentLpuId(Space_B);
	int *lpuCounts = threadState->getLpuCounts(Space_B);
	SpaceB_LPU *lpu = (SpaceB_LPU*) threadState->getCurrentLpu(Space_B, true);
	List<int*> *lpuIdChain = threadState->getLpuIdChainWithoutCopy(Space_B, Space_Root);

	lpu->lpuId[0] = lpuId[0];

	DataPartitionConfig *elementsConfig = partConfigMap->Lookup("elementsSpaceBConfig");
	SpaceA_LPU *spaceALpu = (SpaceA_LPU*) threadState->getCurrentLpu(Space_A);
	PartDimension *elementsParentPartDims = spaceALpu->elementsPartDims;
	elementsConfig->updatePartDimensionInfo(lpuId, lpuCounts, lpu->elementsPartDims, elementsParentPartDims);

	if (taskData != NULL) {
		PartIterator *iterator = threadState->getIterator(Space_B, "elements");
		List<int*> *partId = iterator->getPartIdTemplate();
		elementsConfig->generatePartId(lpuIdChain, partId);
		DataItems *elementsItems = taskData->getDataItemsOfLps("B", "elements");
		DataPart *elementsPart = elementsItems->getDataPart(partId, iterator);
		elementsPart->getMetadata()->updateStorageDimension(lpu->elementsPartDims);
		lpu->elements = (Element*) elementsPart->getData();
	}

	DataPartitionConfig *nodesConfig = partConfigMap->Lookup("nodesSpaceBConfig");
	PartDimension *nodesParentPartDims = spaceALpu->nodesPartDims;
	nodesConfig->updatePartDimensionInfo(lpuId, lpuCounts, lpu->nodesPartDims, nodesParentPartDims);

	if (taskData != NULL) {
		PartIterator *iterator = threadState->getIterator(Space_B, "nodes");
		List<int*> *partId = iterator->getPartIdTemplate();
		nodesConfig->generatePartId(lpuIdChain, partId);
		DataItems *nodesItems = taskData->getDataItemsOfLps("B", "nodes");
		DataPart *nodesPart = nodesItems->getDataPart(partId, iterator);
		nodesPart->getMetadata()->updateStorageDimension(lpu->nodesPartDims);
		lpu->nodes = (Node*) nodesPart->getData();
	}

	DataPartitionConfig *outputConfig = partConfigMap->Lookup("outputSpaceBConfig");
	PartDimension *outputParentPartDims = spaceALpu->outputPartDims;
	outputConfig->updatePartDimensionInfo(lpuId, lpuCounts, lpu->outputPartDims, outputParentPartDims);

	if (taskData != NULL) {
		PartIterator *iterator = threadState->getIterator(Space_B, "output");
		List<int*> *partId = iterator->getPartIdTemplate();
		outputConfig->generatePartId(lpuIdChain, partId);
		DataItems *outputItems = taskData->getDataItemsOfLps("B", "output");
		DataPart *outputPart = outputItems->getDataPart(partId, iterator);
		outputPart->getMetadata()->updateStorageDimension(lpu->outputPartDims);
		lpu->output = (double*) outputPart->getData();
	}
}

/*--------------------------------------------------------------------------------------------------------------
functions to generate PPU IDs and PPU group IDs for a thread
--------------------------------------------------------------------------------------------------------------*/

ThreadIds *ll::getPpuIdsForThread(int threadNo)  {

	ThreadIds *threadIds = new ThreadIds;
	threadIds->threadNo = threadNo;
	threadIds->lpsCount = Space_Count;
	threadIds->ppuIds = new PPU_Ids[Space_Count];
	int idsArray[Space_Count];
	idsArray[Space_Root] = threadNo;

	// for Space Root
	threadIds->ppuIds[Space_Root].lpsName = "Root";
	threadIds->ppuIds[Space_Root].groupId = 0;
	threadIds->ppuIds[Space_Root].groupSize = Total_Threads;
	threadIds->ppuIds[Space_Root].ppuCount = 1;
	threadIds->ppuIds[Space_Root].id = (threadNo == 0) ? 0 : INVALID_ID;

	int threadCount;
	int groupSize;
	int groupThreadId;

	// for Space A;
	threadIds->ppuIds[Space_A].lpsName = "A";
	threadCount = Max_Total_Threads;
	groupSize = threadCount;
	groupThreadId = idsArray[Space_Root] % groupSize;
	threadIds->ppuIds[Space_A].groupId = idsArray[Space_Root] / groupSize;
	threadIds->ppuIds[Space_A].ppuCount = 4;
	threadIds->ppuIds[Space_A].groupSize = groupSize;
	if (groupThreadId == 0) threadIds->ppuIds[Space_A].id
			= threadIds->ppuIds[Space_A].groupId;
	else threadIds->ppuIds[Space_A].id = INVALID_ID;
	idsArray[Space_A] = groupThreadId;

	// for Space B;
	threadIds->ppuIds[Space_B].lpsName = "B";
	threadCount = threadIds->ppuIds[Space_A].groupSize;
	groupSize = threadCount / 64;
	groupThreadId = idsArray[Space_A] % groupSize;
	threadIds->ppuIds[Space_B].groupId = idsArray[Space_A] / groupSize;
	threadIds->ppuIds[Space_B].ppuCount = 64;
	threadIds->ppuIds[Space_B].groupSize = groupSize;
	if (groupThreadId == 0) threadIds->ppuIds[Space_B].id
			= threadIds->ppuIds[Space_B].groupId;
	else threadIds->ppuIds[Space_B].id = INVALID_ID;
	idsArray[Space_B] = groupThreadId;

	return threadIds;
}


void ll::adjustPpuCountsAndGroupSizes(ThreadIds *threadId)  {

	int groupBegin = 0;
	int groupEnd = Total_Threads - 1;

	int groupId = 0;
	int groupSize = Total_Threads;
	int ppuCount = 1;

	groupId = threadId->ppuIds[Space_A].groupId;
	groupSize = threadId->ppuIds[Space_A].groupSize;
	ppuCount = ((groupEnd - groupBegin + 1) + (groupSize - 1)) / groupSize;
	threadId->ppuIds[Space_A].ppuCount = ppuCount;
	groupBegin = groupId * groupSize;
	groupEnd = min(groupBegin + groupSize - 1, groupEnd);
	threadId->ppuIds[Space_A].groupSize = groupEnd - groupBegin + 1;

	groupId = threadId->ppuIds[Space_B].groupId;
	groupSize = threadId->ppuIds[Space_B].groupSize;
	ppuCount = ((groupEnd - groupBegin + 1) + (groupSize - 1)) / groupSize;
	threadId->ppuIds[Space_B].ppuCount = ppuCount;
	groupBegin = groupId * groupSize;
	groupEnd = min(groupBegin + groupSize - 1, groupEnd);
	threadId->ppuIds[Space_B].groupSize = groupEnd - groupBegin + 1;

}


/*--------------------------------------------------------------------------------------------------------------
Thread-State implementation class for the task
--------------------------------------------------------------------------------------------------------------*/

//-------------------------------------------------------------------------------------------LPS Hierarchy Trace

void ThreadStateImpl::setLpsParentIndexMap() {
	lpsParentIndexMap = new int[Space_Count];
	lpsParentIndexMap[Space_Root] = INVALID_ID;
	lpsParentIndexMap[Space_A] = Space_Root;
	lpsParentIndexMap[Space_B] = Space_A;
}

//-----------------------------------------------------------------------------------------Root LPU Construction

void ThreadStateImpl::setRootLpu(Metadata *metadata) {

	ArrayMetadata *arrayMetadata = (ArrayMetadata*) metadata;

	SpaceRoot_LPU *lpu = new SpaceRoot_LPU;
	lpu->elements = NULL;
	lpu->elementsPartDims[0] = PartDimension();
	lpu->elementsPartDims[0].partition = arrayMetadata->elementsDims[0];
	lpu->elementsPartDims[0].storage = arrayMetadata->elementsDims[0].getNormalizedDimension();
	lpu->elementsPartDims[1] = PartDimension();
	lpu->elementsPartDims[1].partition = arrayMetadata->elementsDims[1];
	lpu->elementsPartDims[1].storage = arrayMetadata->elementsDims[1].getNormalizedDimension();
	lpu->elementsPartDims[2] = PartDimension();
	lpu->elementsPartDims[2].partition = arrayMetadata->elementsDims[2];
	lpu->elementsPartDims[2].storage = arrayMetadata->elementsDims[2].getNormalizedDimension();

	lpu->nodes = NULL;
	lpu->nodesPartDims[0] = PartDimension();
	lpu->nodesPartDims[0].partition = arrayMetadata->nodesDims[0];
	lpu->nodesPartDims[0].storage = arrayMetadata->nodesDims[0].getNormalizedDimension();
	lpu->nodesPartDims[1] = PartDimension();
	lpu->nodesPartDims[1].partition = arrayMetadata->nodesDims[1];
	lpu->nodesPartDims[1].storage = arrayMetadata->nodesDims[1].getNormalizedDimension();
	lpu->nodesPartDims[2] = PartDimension();
	lpu->nodesPartDims[2].partition = arrayMetadata->nodesDims[2];
	lpu->nodesPartDims[2].storage = arrayMetadata->nodesDims[2].getNormalizedDimension();

	lpu->output = NULL;
	lpu->outputPartDims[0] = PartDimension();
	lpu->outputPartDims[0].partition = arrayMetadata->outputDims[0];
	lpu->outputPartDims[0].storage = arrayMetadata->outputDims[0].getNormalizedDimension();
	lpu->outputPartDims[1] = PartDimension();
	lpu->outputPartDims[1].partition = arrayMetadata->outputDims[1];
	lpu->outputPartDims[1].storage = arrayMetadata->outputDims[1].getNormalizedDimension();
	lpu->outputPartDims[2] = PartDimension();
	lpu->outputPartDims[2].partition = arrayMetadata->outputDims[2];
	lpu->outputPartDims[2].storage = arrayMetadata->outputDims[2].getNormalizedDimension();

	lpu->setValidBit(true);
	lpsStates[Space_Root]->lpu = lpu;
}

void ThreadStateImpl::setRootLpu(LPU *lpu) {
	lpu->setValidBit(true);
	lpsStates[Space_Root]->lpu = lpu;
}

//------------------------------------------------------------------------------------------State Initialization

void ThreadStateImpl::initializeLPUs() {
	lpsStates[Space_A]->lpu = new SpaceA_LPU;
	lpsStates[Space_A]->lpu->setValidBit(false);
	lpsStates[Space_B]->lpu = new SpaceB_LPU;
	lpsStates[Space_B]->lpu->setValidBit(false);
}

//--------------------------------------------------------------------------------------------LPU Count Function


int *ThreadStateImpl::computeLpuCounts(int lpsId) {
	Hashtable<DataPartitionConfig*> *configMap = getPartConfigMap();
	if (lpsId == Space_Root) {
		return NULL;
	}
	if (lpsId == Space_A) {
		return NULL;
	}
	if (lpsId == Space_B) {
		return getLPUsCountOfSpaceB(configMap);
	}
	return NULL;
}

//-------------------------------------------------------------------------------------LPU Construction Function

LPU *ThreadStateImpl::computeNextLpu(int lpsId) {
	Hashtable<DataPartitionConfig*> *partConfigMap = getPartConfigMap();
	TaskData *taskData = getTaskData();
	if (lpsId == Space_A) {
		SpaceA_LPU *currentLpu = (SpaceA_LPU*) lpsStates[Space_A]->lpu;
		generateSpaceALpu(this, partConfigMap, taskData);
		currentLpu->setValidBit(true);
		return currentLpu;
	}
	if (lpsId == Space_B) {
		SpaceB_LPU *currentLpu = (SpaceB_LPU*) lpsStates[Space_B]->lpu;
		generateSpaceBLpu(this, partConfigMap, taskData);
		currentLpu->setValidBit(true);
		return currentLpu;
	}
	return NULL;
}

//-------------------------------------------------------------------------Reduction Result Map Creator Function

void ThreadStateImpl::initializeReductionResultMap() {
	localReductionResultMap = new Hashtable<reduction::Result*>;
}

/*--------------------------------------------------------------------------------------------------------------
Task Environment Management Structures and Functions
--------------------------------------------------------------------------------------------------------------*/

//---------------------------------------------------------------------------------------------------Constructor

ll::TaskEnvironmentImpl::TaskEnvironmentImpl() : TaskEnvironment() {
	prepareItemsMap();
	resetEnvInstructions();
}

//---------------------------------------------------------------------Task Environment Function Implementations

void ll::TaskEnvironmentImpl::prepareItemsMap() {

	if (envItems->Lookup("output") == NULL) {
		EnvironmentLinkKey *key0 = new EnvironmentLinkKey("output", 0);
		TaskItem *item0 = new TaskItem(key0, OUT, 3, sizeof(double));
		item0->setEnvironment(this);
		envItems->Enter("output", item0);
	}
}

void ll::TaskEnvironmentImpl::setDefaultTaskCompletionInstrs() {

	TaskItem *outputItem = envItems->Lookup("output");
	ChangeNotifyInstruction *instr0 = new ChangeNotifyInstruction(outputItem);
	addEndEnvInstruction(instr0);
}

//--------------------------------------------------------------------------Environmental Links Object Generator

EnvironmentLinks ll::initiateEnvLinks(TaskEnvironment *environment) {

	EnvironmentLinks links;
	ll::TaskEnvironmentImpl *taskEnv = (ll::TaskEnvironmentImpl *) environment;

	return links;
}

//---------------------------------------------------------------------------------LPS Allocation Preconfigurers

void ll::preconfigureLpsAllocationsInEnv(TaskEnvironment *environment, 
		ArrayMetadata *metadata, 
		Hashtable<DataPartitionConfig*> *partConfigMap) {


	TaskItem *outputItem = environment->getItem("output");
	outputItem->setDimension(0, metadata->outputDims[0]);
	outputItem->setDimension(1, metadata->outputDims[1]);
	outputItem->setDimension(2, metadata->outputDims[2]);
	DataPartitionConfig *outputSpaceBConfig = partConfigMap->Lookup("outputSpaceBConfig");
	LpsAllocation *outputInSpaceB = outputItem->getLpsAllocation("B");
	if (outputInSpaceB == NULL) {
		outputItem->preConfigureLpsAllocation("B", outputSpaceBConfig);
	} else {
		outputInSpaceB->setPartitionConfig(outputSpaceBConfig);
	}
}

//------------------------------------------------------------------------------------Non-array variables copier

void ll::copyBackNonArrayEnvVariables(TaskEnvironment *environment, TaskGlobals *taskGlobals) {
	ll::TaskEnvironmentImpl *taskEnv = (ll::TaskEnvironmentImpl *) environment;
}

/*--------------------------------------------------------------------------------------------------------------
task executor function
--------------------------------------------------------------------------------------------------------------*/

void ll::execute(TaskEnvironment *environment, 
		int mesh_size, 
		int iterations, 
		LLPartition partition, 
		int segmentId, 
		std::ofstream &logFile) {

	environment->setLogFile(&logFile);
	if (segmentId >= Max_Segments_Count) {
		logFile << "Current segment does not participate in: LuLesh\n";
		return;
	}

	// setting the total-number-of-threads static variable
	int mpiProcessCount;
	MPI_Comm_size(MPI_COMM_WORLD, &mpiProcessCount);
	int activeSegments = min(mpiProcessCount, Max_Segments_Count);
	Total_Threads = activeSegments * Threads_Per_Segment;

	// initializing environment-links object
	EnvironmentLinks envLinks = initiateEnvLinks(environment);

	// declaring other task related common variables
	TaskGlobals taskGlobals;
	ThreadLocals threadLocals;
	ArrayMetadata *metadata = new ArrayMetadata;

	// declaring and initiating segment execution timer
	struct timeval start;
	gettimeofday(&start, NULL);

	// copying partitioning parameters into an array
	int *partitionArgs = NULL;
	partitionArgs = new int[1];
	partitionArgs[0] = partition.p;

	// invoking the initializer function
	initializeTask(metadata, envLinks, &taskGlobals, &threadLocals, partition, mesh_size, iterations);
	metadata->elementsDims[0].setLength();
	metadata->elementsDims[1].setLength();
	metadata->elementsDims[2].setLength();
	metadata->nodesDims[0].setLength();
	metadata->nodesDims[1].setLength();
	metadata->nodesDims[2].setLength();
	metadata->outputDims[0].setLength();
	metadata->outputDims[1].setLength();
	metadata->outputDims[2].setLength();
	logFile << "\ttask initialization is complete\n";
	logFile.flush();

	// declaring and initializing state variables for threads 
	ThreadLocals *threadLocalsList[Total_Threads];
	for (int i = 0; i < Total_Threads; i++) {
		threadLocalsList[i] = new ThreadLocals;
		*threadLocalsList[i] = threadLocals;
	}
	int lpsDimensions[Space_Count];
	lpsDimensions[Space_Root] = 0;
	lpsDimensions[Space_A] = 0;
	lpsDimensions[Space_B] = 1;
	ThreadIds *threadIdsList[Total_Threads];
	for (int i = 0; i < Total_Threads; i++) {
		threadIdsList[i] = getPpuIdsForThread(i);
		adjustPpuCountsAndGroupSizes(threadIdsList[i]);
	}
	int *ppuCounts = threadIdsList[0]->getAllPpuCounts();
	Hashtable<DataPartitionConfig*> *configMap = 
			getDataPartitionConfigMap(metadata, partition, ppuCounts);
	ThreadStateImpl *threadStateList[Total_Threads];
	for (int i = 0; i < Total_Threads; i++) {
		threadStateList[i] = new ThreadStateImpl(Space_Count, 
				lpsDimensions, partitionArgs, threadIdsList[i]);
		threadStateList[i]->initializeLPUs();
		threadStateList[i]->setLpsParentIndexMap();
		threadStateList[i]->setPartConfigMap(configMap);
	}

	// setting up root LPU reference in each thread's state
	for (int i = 0; i < Total_Threads; i++) {
		threadStateList[i]->setRootLpu(metadata);
	}

	// grouping threads into segments
	List<SegmentState*> *segmentList = new List<SegmentState*>;
	int segmentCount = Total_Threads / Threads_Per_Segment;
	int threadIndex = 0;
	for (int s = 0; s < segmentCount; s++) {
		SegmentState *segment = new SegmentState(s, s);
		int participantCount = 0;
		while (participantCount < Threads_Per_Segment) {
			segment->addParticipant(threadStateList[threadIndex]);
			threadIndex++;
			participantCount++;
		}
		segmentList->Append(segment);
	}
	SegmentState *mySegment = segmentList->Nth(segmentId);
	int participantStart = segmentId * Threads_Per_Segment;
	int participantEnd = participantStart + Threads_Per_Segment - 1;
	logFile << "\tsegment grouping of threads is complete\n";
	logFile.flush();

	// initializing segment memory
	TaskData *taskData = initializeTaskData(mySegment->getParticipantList(), 
			metadata, environment, mySegment, partition, ppuCounts);
	for (int i = participantStart; i <= participantEnd; i++) {
		threadStateList[i]->setTaskData(taskData);
		threadStateList[i]->setPartIteratorMap(taskData->generatePartIteratorMap());
		threadStateList[i]->initiateLogFile("ll");
		threadStateList[i]->enableLogging();
	}
	delete[] ppuCounts;
	logFile << "\tmemory allocation is complete\n";
	logFile.flush();

	// calculating memory and threads preparation time
	struct timeval end;
	gettimeofday(&end, NULL);
	double allocationTime = ((end.tv_sec + end.tv_usec / 1000000.0)
			- (start.tv_sec + start.tv_usec / 1000000.0));
	logFile << "Memory preparation time: " << allocationTime << " Seconds" << std::endl;
	double timeConsumedSoFar = allocationTime;
	logFile.flush();

	// starting threads
	logFile << "\tlaunching threads\n";
	logFile.flush();
	pthread_t threads[Total_Threads];
	PThreadArg *threadArgs[Total_Threads];
	for (int i = 0; i < Total_Threads; i++) {
		threadArgs[i] = new PThreadArg;
		threadArgs[i]->taskName = "LuLesh";
		threadArgs[i]->metadata = metadata;
		threadArgs[i]->taskGlobals = &taskGlobals;
		threadArgs[i]->threadLocals = threadLocalsList[i];
		threadArgs[i]->partition = partition;
		threadArgs[i]->threadState = threadStateList[i];
	}
	pthread_attr_t attr;
	cpu_set_t cpus;
	pthread_attr_init(&attr);
	int state;
	for (int i = participantStart; i <= participantEnd; i++) {
		int cpuId = (i * Core_Jump / Threads_Per_Core) % Processors_Per_Phy_Unit;
		int physicalId = Processor_Order[cpuId];
		CPU_ZERO(&cpus);
		CPU_SET(physicalId, &cpus);
		pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpus);
		state = pthread_create(&threads[i], &attr, runPThreads, (void *) threadArgs[i]);
		if (state) {
			std::cout << "Could not start some PThread" << std::endl;
			std::exit(EXIT_FAILURE);
		} else {
			logFile << "\t\tlaunched thread #" << i << "\n";
			logFile.flush();
		}
	}
	for (int i = participantStart; i <= participantEnd; i++) {
		pthread_join(threads[i], NULL);
	}


	// calculating computation time
	gettimeofday(&end, NULL);
	double computationTime = ((end.tv_sec + end.tv_usec / 1000000.0)
			- (start.tv_sec + start.tv_usec / 1000000.0)) - timeConsumedSoFar;
	logFile << "Computation time: " << computationTime << " Seconds" << std::endl;
	timeConsumedSoFar += computationTime;
	logFile.flush();

	double compAndOverheadTime = timeConsumedSoFar - allocationTime;
	logFile << "Computation + overhead time: " << compAndOverheadTime << " Seconds" << std::endl;
	logFile.flush();

	// doing task end environmental processing and memory cleanup
	copyBackNonArrayEnvVariables(environment, &taskGlobals);
	environment->executeTaskCompletionInstructions();
	delete taskData;
}


/*--------------------------------------------------------------------------------------------------------------
function for the initialize block
--------------------------------------------------------------------------------------------------------------*/

void ll::initializeTask(ArrayMetadata *arrayMetadata, 
		EnvironmentLinks environmentLinks, 
		TaskGlobals *taskGlobals, 
		ThreadLocals *threadLocals, 
		LLPartition partition, 
		int mesh_size, 
		int iterations) {

	taskGlobals->node_size = (mesh_size + 1);
	taskGlobals->element_size = (taskGlobals->node_size - 1);
	arrayMetadata->nodesDims[0].range.min = 0;
	arrayMetadata->nodesDims[0].range.max = (taskGlobals->node_size - 1);
	arrayMetadata->nodesDims[1] = arrayMetadata->nodesDims[0];
	arrayMetadata->nodesDims[2] = arrayMetadata->nodesDims[0];
	arrayMetadata->elementsDims[0].range.min = 0;
	arrayMetadata->elementsDims[0].range.max = (taskGlobals->element_size - 1);
	arrayMetadata->elementsDims[1] = arrayMetadata->elementsDims[0];
	arrayMetadata->elementsDims[2] = arrayMetadata->elementsDims[0];
	taskGlobals->max_iterations = iterations;
	arrayMetadata->outputDims[0].range.min = 0;
	arrayMetadata->outputDims[0].range.max = (taskGlobals->element_size - 1);
	arrayMetadata->outputDims[1] = arrayMetadata->outputDims[0];
	arrayMetadata->outputDims[2] = arrayMetadata->outputDims[0];
}


/*--------------------------------------------------------------------------------------------------------------
functions for compute stages
--------------------------------------------------------------------------------------------------------------*/

int ll::calcelemshapefunctionderivatives_stage_3(SpaceB_LPU *lpu, 
		ArrayMetadata *arrayMetadata, 
		TaskGlobals *taskGlobals, 
		ThreadLocals *threadLocals, 
		LLPartition partition, 
		std::ofstream &logFile) {

	//-------------------- Local Copies of Metadata -----------------------------

	// create local copies of partition and storage dimension configs of all arrays
	Dimension elementsPartDims[3];
	elementsPartDims[0] = lpu->elementsPartDims[0].partition;
	elementsPartDims[1] = lpu->elementsPartDims[1].partition;
	elementsPartDims[2] = lpu->elementsPartDims[2].partition;
	Dimension elementsStoreDims[3];
	elementsStoreDims[0] = lpu->elementsPartDims[0].storage;
	elementsStoreDims[1] = lpu->elementsPartDims[1].storage;
	elementsStoreDims[2] = lpu->elementsPartDims[2].storage;
	Dimension nodesPartDims[3];
	nodesPartDims[0] = lpu->nodesPartDims[0].partition;
	nodesPartDims[1] = lpu->nodesPartDims[1].partition;
	nodesPartDims[2] = lpu->nodesPartDims[2].partition;
	Dimension nodesStoreDims[3];
	nodesStoreDims[0] = lpu->nodesPartDims[0].storage;
	nodesStoreDims[1] = lpu->nodesPartDims[1].storage;
	nodesStoreDims[2] = lpu->nodesPartDims[2].storage;
	Dimension outputPartDims[3];
	outputPartDims[0] = lpu->outputPartDims[0].partition;
	outputPartDims[1] = lpu->outputPartDims[1].partition;
	outputPartDims[2] = lpu->outputPartDims[2].partition;
	Dimension outputStoreDims[3];
	outputStoreDims[0] = lpu->outputPartDims[0].storage;
	outputStoreDims[1] = lpu->outputPartDims[1].storage;
	outputStoreDims[2] = lpu->outputPartDims[2].storage;

	// create a local part-dimension object for later use
	PartDimension partConfig;

	// create a local transformed index variable for later use
	int xformIndex;

	//------------------- Local Variable Declarations ---------------------------

	double cjxet;
	double cjxxi;
	double cjxze;
	double cjyet;
	double cjyxi;
	double cjyze;
	double cjzet;
	double cjzxi;
	double cjzze;
	double fjxet;
	double fjxxi;
	double fjxze;
	double fjyet;
	double fjyxi;
	double fjyze;
	double fjzet;
	double fjzxi;
	double fjzze;
	int lpuId[1];

	//----------------------- Computation Begins --------------------------------

	{// scope entrance for parallel loop on index i
	int i;
	int iterationStart = elementsPartDims[0].range.min;
	int iterationBound = elementsPartDims[0].range.max;
	int indexIncrement = 1;
	int indexMultiplier = 1;
	if (elementsPartDims[0].range.min > elementsPartDims[0].range.max) {
		iterationBound *= -1;
		indexIncrement *= -1;
		indexMultiplier = -1;
	}
	for (i = iterationStart; 
			indexMultiplier * i <= iterationBound; 
			i += indexIncrement) {
		long int inodes0 = ((long) (i - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length))
				 * ((long) (nodesStoreDims[1].length));
		long int ielements0 = ((long) (i - elementsStoreDims[0].range.min)) * ((long) (elementsStoreDims[2].length))
				 * ((long) (elementsStoreDims[1].length));
		long int ioutput0 = ((long) (i - outputStoreDims[0].range.min)) * ((long) (outputStoreDims[2].length))
				 * ((long) (outputStoreDims[1].length));
		{// scope entrance for parallel loop on index j
		int j;
		int iterationStart = elementsPartDims[1].range.min;
		int iterationBound = elementsPartDims[1].range.max;
		int indexIncrement = 1;
		int indexMultiplier = 1;
		if (elementsPartDims[1].range.min > elementsPartDims[1].range.max) {
			iterationBound *= -1;
			indexIncrement *= -1;
			indexMultiplier = -1;
		}
		for (j = iterationStart; 
				indexMultiplier * j <= iterationBound; 
				j += indexIncrement) {
			long int jnodes1 = ((long) (j - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length));
			long int jelements1 = ((long) (j - elementsStoreDims[1].range.min)) * ((long) (elementsStoreDims[2].length));
			long int joutput1 = ((long) (j - outputStoreDims[1].range.min)) * ((long) (outputStoreDims[2].length));
			{// scope entrance for parallel loop on index k
			int k;
			int iterationStart = elementsPartDims[2].range.min;
			int iterationBound = elementsPartDims[2].range.max;
			int indexIncrement = 1;
			int indexMultiplier = 1;
			if (elementsPartDims[2].range.min > elementsPartDims[2].range.max) {
				iterationBound *= -1;
				indexIncrement *= -1;
				indexMultiplier = -1;
			}
			for (k = iterationStart; 
					indexMultiplier * k <= iterationBound; 
					k += indexIncrement) {
				long int knodes2 = ((long) (k - nodesStoreDims[2].range.min));
				long int kelements2 = ((long) (k - elementsStoreDims[2].range.min));
				long int koutput2 = ((long) (k - outputStoreDims[2].range.min));
				fjxxi = (0.125 * ((((lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[inodes0 + jnodes1 + knodes2].x) + (lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].x)) - (lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + knodes2].x)) - (lpu->nodes[inodes0 + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].x)));
				fjxet = (0.125 * ((((lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[inodes0 + jnodes1 + knodes2].x) - (lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].x)) + (lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + knodes2].x)) - (lpu->nodes[inodes0 + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].x)));
				fjxze = (0.125 * ((((lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[inodes0 + jnodes1 + knodes2].x) + (lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].x)) + (lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + knodes2].x)) + (lpu->nodes[inodes0 + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].x - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].x)));
				fjyxi = (0.125 * ((((lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[inodes0 + jnodes1 + knodes2].y) + (lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].y)) - (lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + knodes2].y)) - (lpu->nodes[inodes0 + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].y)));
				fjyet = (0.125 * ((((lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[inodes0 + jnodes1 + knodes2].y) - (lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].y)) + (lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + knodes2].y)) - (lpu->nodes[inodes0 + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].y)));
				fjyze = (0.125 * ((((lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[inodes0 + jnodes1 + knodes2].y) + (lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].y)) + (lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + knodes2].y)) + (lpu->nodes[inodes0 + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].y - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].y)));
				fjzxi = (0.125 * ((((lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[inodes0 + jnodes1 + knodes2].z) + (lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].z)) - (lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + knodes2].z)) - (lpu->nodes[inodes0 + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].z)));
				fjzet = (0.125 * ((((lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[inodes0 + jnodes1 + knodes2].z) - (lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].z)) + (lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + knodes2].z)) - (lpu->nodes[inodes0 + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].z)));
				fjzze = (0.125 * ((((lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[inodes0 + jnodes1 + knodes2].z) + (lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].z)) + (lpu->nodes[inodes0 + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + jnodes1 + knodes2].z)) + (lpu->nodes[inodes0 + jnodes1 + ((long) ((k + 1) - nodesStoreDims[2].range.min))].z - lpu->nodes[((long) ((i + 1) - nodesStoreDims[0].range.min)) * ((long) (nodesStoreDims[2].length)) * ((long) (nodesStoreDims[1].length)) + ((long) ((j + 1) - nodesStoreDims[1].range.min)) * ((long) (nodesStoreDims[2].length)) + knodes2].z)));
				cjxxi = ((fjyet * fjzze) - (fjzet * fjyze));
				cjxet = ((0 - (fjyxi * fjzze)) + (fjzxi * fjyze));
				cjxze = ((fjyxi * fjzet) - (fjzxi * fjyet));
				cjyxi = ((0 - (fjxet * fjzze)) + (fjzet * fjxze));
				cjyet = ((fjxxi * fjzze) - (fjzxi * fjxze));
				cjyze = ((0 - (fjxxi * fjzet)) + (fjzxi * fjxet));
				cjzxi = ((fjxet * fjyze) - (fjyet * fjxze));
				cjzet = ((0 - (fjxxi * fjyze)) + (fjyxi * fjxze));
				cjzze = ((fjxxi * fjyet) - (fjyxi * fjxet));
				lpu->elements[ielements0 + jelements1 + kelements2].normalX[0][0][0] = (((0 - cjxxi) - cjxet) - cjxze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalX[1][0][0] = ((cjxxi - cjxet) - cjxze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalX[1][1][0] = ((cjxxi + cjxet) - cjxze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalX[0][1][0] = (((0 - cjxxi) + cjxet) - cjxze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalX[0][0][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalX[0][0][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalX[1][0][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalX[1][0][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalX[1][1][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalX[1][1][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalX[0][1][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalX[0][1][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalY[0][0][0] = (((0 - cjyxi) - cjyet) - cjyze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalY[1][0][0] = ((cjyxi - cjyet) - cjyze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalY[1][1][0] = ((cjyxi + cjyet) - cjyze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalY[0][1][0] = (((0 - cjyxi) + cjyet) - cjyze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalY[0][0][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalY[0][0][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalY[1][0][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalY[1][0][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalY[1][1][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalY[1][1][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalY[0][1][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalY[0][1][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalZ[0][0][0] = (((0 - cjzxi) - cjzet) - cjzze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalZ[1][0][0] = ((cjzxi - cjzet) - cjzze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalZ[1][1][0] = ((cjzxi + cjzet) - cjzze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalZ[0][1][0] = (((0 - cjzxi) + cjzet) - cjzze);
				lpu->elements[ielements0 + jelements1 + kelements2].normalZ[0][0][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalZ[0][0][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalZ[1][0][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalZ[1][0][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalZ[1][1][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalZ[1][1][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].normalZ[0][1][1] = (0 - lpu->elements[ielements0 + jelements1 + kelements2].normalZ[0][1][0]);
				lpu->elements[ielements0 + jelements1 + kelements2].volume = (8 * (((fjxet * cjxet) + (fjyet * cjyet)) + (fjzet * cjzet)));
				lpu->output[ioutput0 + joutput1 + koutput2] = lpu->elements[ielements0 + jelements1 + kelements2].volume;
			}
			}// scope exit for parallel loop on index k
		}
		}// scope exit for parallel loop on index j
	}
	}// scope exit for parallel loop on index i

	//------------------------- Returning Flag ----------------------------------

	return SUCCESS_RUN;
}


/*--------------------------------------------------------------------------------------------------------------
run method for thread simulating the task flow
--------------------------------------------------------------------------------------------------------------*/

void ll::run(ArrayMetadata *arrayMetadata, 
		TaskGlobals *taskGlobals, 
		ThreadLocals *threadLocals, 
		LLPartition partition, ThreadStateImpl *threadState) {

	// log thread's affinity information
	threadState->logThreadAffinity();

	// set the root LPU in the thread state so that calculation can start
	LPU *rootLpu = threadState->getCurrentLpu(Space_Root);
	if (rootLpu == NULL) {
		threadState->setRootLpu(arrayMetadata);
	}

	// create a local part-dimension object for later use
	PartDimension partConfig;

	// create a local transformed index variable for later use
	int xformIndex;

	{ // scope entrance for iterating LPUs of Space A
	int spaceALpuId = INVALID_ID;
	int spaceAIteration = 0;
	SpaceA_LPU *spaceALpu = NULL;
	LPU *lpu = NULL;
	while((lpu = threadState->getNextLpu(Space_A, Space_Root, spaceALpuId)) != NULL) {
		spaceALpu = (SpaceA_LPU*) lpu;

		{ // scope entrance for iterating LPUs of Space B
		int spaceBLpuId = INVALID_ID;
		int spaceBIteration = 0;
		SpaceB_LPU *spaceBLpu = NULL;
		LPU *lpu = NULL;
		while((lpu = threadState->getNextLpu(Space_B, Space_A, spaceBLpuId)) != NULL) {
			spaceBLpu = (SpaceB_LPU*) lpu;
			if (threadState->isValidPpu(Space_B)) {
				// invoking user computation
				int stage3Executed = calcelemshapefunctionderivatives_stage_3(spaceBLpu, 
						arrayMetadata, 
						taskGlobals, 
						threadLocals, 
						partition, 
						threadState->threadLog);
			}
			spaceBLpuId = spaceBLpu->id;
			spaceBIteration++;
		}
		threadState->removeIterationBound(Space_A);
		} // scope exit for iterating LPUs of Space B
		spaceALpuId = spaceALpu->id;
		spaceAIteration++;
	}
	} // scope exit for iterating LPUs of Space A

	// logging iterators' efficiency
	threadState->logIteratorStatistics();

	// close thread's log file
	threadState->closeLogFile();
}

/*-----------------------------------------------------------------------------------
PThreads run function
------------------------------------------------------------------------------------*/

void *ll::runPThreads(void *argument) {
	PThreadArg *pthreadArg = (PThreadArg *) argument;
	ThreadStateImpl *threadState = pthreadArg->threadState;
	run(pthreadArg->metadata, 
			pthreadArg->taskGlobals, 
			pthreadArg->threadLocals, 
			pthreadArg->partition, 
			threadState);
	pthread_exit(NULL);
}


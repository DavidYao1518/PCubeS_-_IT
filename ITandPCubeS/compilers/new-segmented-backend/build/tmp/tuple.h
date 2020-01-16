#ifndef _H_tuple
#define _H_tuple

#include <iostream>
#include <vector>

#include "../../../common-libs/domain-obj/structure.h"

class ProgramArgs;
class Node;
class Element;
class LLPartition;

class ProgramArgs {
  public:
	int iterations;
	int mesh_size;
	const char* output_file;
	int p;
	ProgramArgs() {
		iterations = 0;
		mesh_size = 0;
		output_file = NULL;
		p = 0;
	}
};

class Node {
  public:
	double x;
	double y;
	double z;
	double xd;
	double yd;
	double zd;
	double xdd;
	double ydd;
	double zdd;
	double fx;
	double fy;
	double fz;
	Node() {
		x = 0;
		y = 0;
		z = 0;
		xd = 0;
		yd = 0;
		zd = 0;
		xdd = 0;
		ydd = 0;
		zdd = 0;
		fx = 0;
		fy = 0;
		fz = 0;
	}
};

class Element {
  public:
	double p;
	double q;
	double normalX[2][2][2];
	double normalY[2][2][2];
	double normalZ[2][2][2];
	double volume;
	double sigxx;
	double sigyy;
	double sigzz;
	Element() {
		p = 0;
		q = 0;
//		normalX = NULL;
//		normalY = NULL;
//		normalZ = NULL;
		volume = 0;
		sigxx = 0;
		sigyy = 0;
		sigzz = 0;
	}
};

class LLPartition {
  public:
	int p;
	LLPartition() {
		p = 0;
	}
};

#endif

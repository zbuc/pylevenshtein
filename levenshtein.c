#include <Python.h>

static int min(int * values, int length){
	int i;
	int minval = INT_MAX;
	for(i=0; i<length; i++){
		if(values[i] < minval){
			minval = values[i];		
		}
	}
	return minval;
}

static int edit_distance(char * worda, char * wordb, int i, int j){
	int triad[3];
	if(i==0 && j==0)
		return 0;
	if(i==0)
		return j;
	if(j==0)
		return i;
	if(worda[i-1] == wordb[j-1])
		return edit_distance(worda, wordb, i-1, j-1);
	triad[0] = edit_distance(worda, wordb, i-1, j);
	triad[1] = edit_distance(worda, wordb, i, j-1);
	triad[2] = edit_distance(worda, wordb, i-1, j-1);
	return min(triad, 3) + 1;
}

PyObject *PyEditDistance(PyObject *self, PyObject *args){
	char * worda, * wordb;
	int distance;

	if(PyArg_ParseTuple(args, "ss", &worda, &wordb)){
		distance = edit_distance(worda, wordb, 
						strlen(worda), strlen(wordb));
		return Py_BuildValue("i", distance);
	}

	return NULL;
}

PyMethodDef methods[] = {
	{"edit_distance", PyEditDistance},
	{NULL, NULL},
};

void initlevenshtein(){
	PyObject *m, *d;

	m = Py_InitModule("levenshtein", methods);
	if(m==NULL) return;

}



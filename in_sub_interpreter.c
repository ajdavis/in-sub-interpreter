#include <Python.h>

static PyObject* in_sub_interpreter(PyObject* self, PyObject* args)
{
    static PyInterpreterState* main_interpreter = NULL;
    PyInterpreterState* interpreter;

    if (main_interpreter == NULL) {
        interpreter = PyInterpreterState_Head();
        while (interpreter->next)
            interpreter = interpreter->next;
        main_interpreter = interpreter;
    }

    if (main_interpreter == PyThreadState_Get()->interp) {
        Py_RETURN_FALSE;
    } else {
        Py_RETURN_TRUE;
    }
}

static PyMethodDef Methods[] =
{
     {
         "in_sub_interpreter", in_sub_interpreter, METH_NOARGS,
         "Returns True if running in a Python sub interpreter."
     },
     {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC

initin_sub_interpreter(void)
{
     (void) Py_InitModule("in_sub_interpreter", Methods);
}

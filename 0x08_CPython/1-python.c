#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p)
{
    int size = (((PyVarObject*)(p))->ob_size);
    int alloc = (((PyListObject*)(p))->allocated);
    printf("[*] Python list info\n[*] Size of the Python List = %d\n[*] Allocated = %d\n", size, alloc);
    int i;
    for (i = 0; i < size; i++)
        printf("Element %d: %s\n", i, PyList_GetItem(p, i)->ob_type->tp_name);
}
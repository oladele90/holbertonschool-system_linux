#include <Python.h>
#include <stdio.h>

void print_python_bytes(PyObject *p)
{
    int i;
    int size = (((PyVarObject*)(p))->ob_size);
    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
		return;
    }
    printf("  size: %d\n", size);
    printf("  trying string: %s\n", ((PyBytesObject *)p)->ob_sval);
    if (size > 9)
        size = 10;
    else
        size++;
    printf("  first %d bytes: ", size);
    for (i = 0; i < size; i++)
    {
        printf("%02hhx", (((PyBytesObject*)(p))->ob_sval[i]));
        if (i == size - 1)
            printf("\n");
        else
            printf(" ");
        
    }
}

void print_python_list(PyObject *p)
{
    int size = (((PyVarObject*)(p))->ob_size);
    int alloc = (((PyListObject*)(p))->allocated);
    printf("[*] Python list info\n[*] Size of the Python List = %d\n[*] Allocated = %d\n", size, alloc);
    int i;
    for (i = 0; i < size; i++)
    {
        PyObject *item = (((PyListObject*)(p))->ob_item[i]);
        printf("Element %d: %s\n", i, item->ob_type->tp_name);
        if (PyBytes_Check(item))
        {
            print_python_bytes(item);
        }
    }
}
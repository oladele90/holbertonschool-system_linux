#include <Python.h>
#include <stdio.h>

void print_python_string(PyObject *p)
{
    wprintf(L"[.] string object info\n");
    if (!(PyUnicode_Check(p)))
    {
        wprintf(L"  [ERROR] Invalid String Object\n");
	    return;
    }
    if (PyUnicode_IS_COMPACT_ASCII(p))
        wprintf(L"  type: compact ascii\n");
    else
        wprintf(L"  type: compact unicode object\n");
	wprintf(L"  length: %ld\n", ((PyASCIIObject *)p)->length);
	wprintf(L"  value: %ls\n", PyUnicode_AS_UNICODE(p));
}

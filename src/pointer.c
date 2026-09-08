/* Recovered large-model far function: write 1 through a far pointer.
 * CL.EXE /c /f- /AL /Gs /Os /Zl → 55 8B EC C4 5E 06 26 C6 07 01 5D CB
 */
void far foo(char far *p)
{
    p[0] = 1;
}

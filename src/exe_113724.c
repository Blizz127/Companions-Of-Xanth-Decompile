long far helper(void);

void far exe_113724(unsigned a)
{
    long limit;

    limit = helper() + a;
    do {
    } while (helper() < limit);
}

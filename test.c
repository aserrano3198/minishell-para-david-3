int main (int argc, char **argv)
{
	int i = 1;
	while (--argc >= 1)
		printf("%s\n", argv[i++]);
	printf("end test\n");
}

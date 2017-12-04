void foo(char **p) {
	printf("%x\n", p);
}
int main() {
	char line[] = "hello";
	printf("%x", line);
	foo(&line);
}

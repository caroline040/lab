#include "myls.h"

int main(int argc, char **argv)
{
	umask(0);
	struct stat s;
	char *path;

	/**********************************
	   obtain the file-info structure
	***********************************/
	if(argc == 1){
		path = ".";
		Stat(path, &s);
	}
	else if(argc == 2){
		path = argv[1];
		Stat(path, &s);
	}
	else
		err_quit("too many arguments.\n");

	/************
	  Directory
	*************/
	if((s.st_mode & S_IFMT) == S_IFDIR){
		DIR *dp;
		struct dirent *ep;

		dp = Opendir(path);

		chdir(path);
		while((ep=readdir(dp)) != NULL){

			if(ep->d_name[0] == '.')
				continue;

			lstat(ep->d_name, &s);

			printf("%s%3d %7s %7s%8s %.16s ",
				mode(&s), hln(&s), user(&s), group(&s),
				size_dev(&s), mtime(&s));
			print_color_name(&s, ep->d_name);
		}

		Closedir(dp);
	}

	/*********
	   File
	**********/
	else{
		printf("%s%3d %7s %7s%8s %.16s ", mode(&s), hln(&s),
			user(&s), group(&s), size_dev(&s), mtime(&s));
		print_color_name(&s, path);
	}
		
	exit(0);
}

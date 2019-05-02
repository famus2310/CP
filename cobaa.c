void* joinVideo() {
	char videoPath[1000] = "/Video";
	enkripsi(videoPath);
	mkdir(videoPath, 777);

	DIR *dirvideo;
	struct dirent *de, **fileList;
	dirvideo = opendir(videoPath);
	if (dirvideo == NULL) {
		return NULL;
	}
	int n = scandir(dirpath, &fileList, 0, alphasort);
	int i = 0;
	while(i < n){
		de = fileList[i];
		i++;
		// int lastDotChar = getLastCharPos(de->d_name, '.');
		if (de->d_type != DT_REG)
			continue;
		
		// if (lastDotChar==0 || strlen(de->d_name)<4 || !((de->d_name[lastDotChar-3]=='m' && de->d_name[lastDotChar-2]=='k' && de->d_name[lastDotChar-1]=='v') || 
		// 	(de->d_name[lastDotChar-3]=='m' && de->d_name[lastDotChar-2]=='p' && de->d_name[lastDotChar-1]=='4')))
		// 	continue;

		sprintf(filePath, "%s/%s", dirpath, de->d_name);
		FILE* source = fopen(filePath, "r");

		de->d_name[lastDotChar] = '\0';
		sprintf(filePath, "%s/%s", videoPath, de->d_name);
		FILE* target = fopen(filePath, "a");

		while ((ch = fgetc(source)) != EOF)
			//if (ch!='\n') 
				fputc(ch, target);

		fclose(source);
		fclose(target);
	}
	
	return NULL;

}

void *xmp_init (struct fuse_conn_info *conn) {

		pthread_create(&tid,NULL,&joinVideo,NULL);
}
void xmp_destroy (void *) {

}

struct fuse {
	.init = xmp_init,
	.destroy = xmp_destroy,
}


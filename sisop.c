#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>


static const char *dirpath = "/home/fandipj/shift4";
char cipher[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
char temp_path[1005];
int key;
pthread_t tid[1005];
int flag = 1;

char enkripsi(char *nama)
{
	char *tmp;
	for(int i=0; i<strlen(nama); i++){
		tmp=strchr(cipher,nama[i]);
		if(tmp){
			int index = tmp - cipher;
			nama[i]=cipher[(index+key)%strlen(cipher)];
		}
	}
	return *nama;
}

char dekripsi(char *nama)
{
	char *tmp;
	for(int i=0; i<strlen(nama); i++){
		tmp=strchr(cipher,nama[i]);
		if(tmp){
			int index = tmp - cipher;
			index = index-key;
			if(index<0)index+=strlen(cipher);
			nama[i]=cipher[index];
		}
	}
	return *nama;
}

void* renamefile(void *arg)
{
	char *path_now = (char*)arg;
	pthread_t id = pthread_self();
	//while(1){
		if (pthread_equal(id, tid[0])) {
			if (strstr(path_now, "/YOUTUBER") != NULL) {
				while (flag == 0) {}
				char newname[1005],oldname[1005];
				enkripsi(path_now);
				sprintf(oldname, "%s%s",dirpath,path_now);
				strcpy(newname, oldname);
				char ext[] = ".iz1";
				enkripsi(ext);
				strcat(newname, ext);
				printf("==****NEWNAME: %s\n", newname);
				rename(oldname, newname);
			}
		}
	//}
	return NULL;
}

void* merge(void *arg) {
	char ret[1005];
	char *fpath = (char*)arg;
	dp = opendir(fpath);
	while ((de = readdir(dp)) != NULL) {
		struct stat st;
		char tmppath[1005];
		strcpy(tmppath, fpath);
		strcat(tmppath, "/");
		strcat(tmppath, de->d_name);
		stat(tmppath, &st);
		if (S_ISREG(st.st_mode) == 0)
			continue;
		if (strlen(de->d_name) < 5)
			continue;
		int sz = strlen(de->d_name);
		if (de->d_name[strlen - 1] != '0' || de->d_name[strlen - 2] != '0' || de->d_name[strlen - 3] != '0'
			|| de->d_name[strlen - 4] != '.')
			continue;
		pthread_create(&(tid[0]), NULL, &merge, tmppath);
	}
}

static int xmp_getattr(const char *path, struct stat *stbuf)
{
  int res;
	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum getattr: %s---------------\n", path_temp);
	
	enkripsi(path_temp);
	
	sprintf(fpath,"%s%s",dirpath,path_temp);
	
	printf("------path_temp setelah getattr: %s------\n",path_temp);
	printf("------fpath: %s------\n",fpath);
	
	res = lstat(fpath, stbuf);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
		       off_t offset, struct fuse_file_info *fi)
{
  	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum readdir: %s---------------\n", path_temp);
	
	enkripsi(path_temp);
	
	printf("--------------path_temp setelah readdir: %s---------------\n", path_temp);
	
	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if readdir: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path1 dalam else readdir: %s---------------\n", fpath);
	} 
	int res = 0;

	DIR *dp;
	struct dirent *de;

	(void) offset;
	(void) fi;

	dp = opendir(fpath);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) {
		struct stat st;
		memset(&st, 0, sizeof(st));
		st.st_ino = de->d_ino;
		st.st_mode = de->d_type << 12;
		struct stat tmp;
		if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
			continue;
		}
		char tmppath[1005];
		strcpy(tmppath, fpath);
		strcat(tmppath, "/");
		strcat(tmppath, de->d_name);
		stat(tmppath, &tmp);
		dekripsi(de->d_name);
		printf("NAMA FILE %s\n", de->d_name);
		struct passwd *pw = getpwuid(tmp.st_uid);
		struct group *gr = getgrgid(tmp.st_gid);
		printf("Name %s, Group %s\n", pw->pw_name, gr->gr_name);
		if ((strcmp(pw->pw_name, "chipset") == 0 || strcmp(pw->pw_name, "ic_controller") == 0) && strcmp(gr->gr_name, "rusak") == 0
			&&  (tmp.st_mode & 4) == 0) {
			printf("Masuk Pak Eko\n");
			FILE* fptr;
			char accesstime[55];
			time_t t = tmp.st_atime;
			struct tm lt;
			localtime_r(&t, &lt);

			// strftime(timbuf, sizeof(timbuf), "%c", &lt);
			strftime(accesstime, 55, "%d.%m.%Y %H:%M:%S", &lt);
			char buffer[1005];
			memset(buffer, 0, sizeof(buffer));
			strcat(buffer, de->d_name);
			enkripsi(de->d_name);
			strcat(buffer, " ");
			strcat(buffer, gr->gr_name);
			strcat(buffer, " ");
			strcat(buffer, pw->pw_name);
			strcat(buffer, " ");
			strcat(buffer, accesstime);
			char miris[1005] = "miris.txt";
			enkripsi(miris);
			char dest[1005];
			strcpy(dest, fpath);
			strcat(dest, "/");
			strcat(dest, miris);
			// enkripsi(de->d_name);
			printf("%s\n", dest);
			fptr = fopen(dest, "a+");
			printf("%s\n", buffer);
			fprintf(fptr, "%s\n", buffer);
			fclose(fptr);
			printf("%s\n", de->d_name);
			strcpy(dest, fpath);
			strcat(dest, "/");
			strcat(dest, de->d_name);
			remove(dest);
			continue;
		}

		// if (strstr(path, "/YOUTUBER") != NULL) {
		// 	char tempname[1005];
		// 	strcpy(tempname, de->d_name);
		// 	if (S_ISREG(st.st_mode))
		// 		strcat(tempname, ".iz1");

		// 	// printf("NAMANYA %s\n", tempname);
		// 	res = (filler(buf, tempname, &st, 0));
		// } else
			res = (filler(buf, de->d_name, &st, 0));
		if(res!=0) break;
	}

	closedir(dp);
	return 0;
}

static int xmp_mkdir(const char *path, mode_t mode)
{
	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum mkdir: %s---------------\n", path_temp);
	if (strstr(path_temp, "/YOUTUBER") != NULL) {
		mode = 0000750;
	}
	
	enkripsi(path_temp);
	
	printf("--------------path_temp setelah mkdir: %s---------------\n", path_temp);

	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if mkdir: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path dalam else mkdir: %s---------------\n", fpath);
	}
    int res;

    res = mkdir(fpath, mode);
    if(res == -1)
        return -errno;

    return 0;
}

static int xmp_read(const char *path, char *buf, size_t size, off_t offset,
		    struct fuse_file_info *fi)
{
  	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum readdir: %s---------------\n", path_temp);
	
	enkripsi(path_temp);
	
	printf("--------------path_temp setelah readdir: %s---------------\n", path_temp);
	
	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if readdir: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path1 dalam else readdir: %s---------------\n", fpath);
	}
	
	int res = 0;
  	int fd = 0 ;

	(void) fi;
	fd = open(fpath, O_RDONLY);
	if (fd == -1)
		return -errno;

	res = pread(fd, buf, size, offset);
	if (res == -1)
		res = -errno;

	close(fd);
	return res;
}

static int xmp_write(const char *path, const char *buf, size_t size,
		     off_t offset, struct fuse_file_info *fi)
{
	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum readdir: %s---------------\n", path_temp);
	
	enkripsi(path_temp);
	
	printf("--------------path_temp setelah readdir: %s---------------\n", path_temp);
	
	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if readdir: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path1 dalam else readdir: %s---------------\n", fpath);
	}

	int fd;
	int res;

	(void) fi;
	fd = open(fpath, O_WRONLY);
	if (fd == -1)
		return -errno;

	res = pwrite(fd, buf, size, offset);
	if (res == -1)
		res = -errno;

	close(fd);

	pthread_create(&(tid[0]), NULL, &backup, NULL);


	return res;
}

void* merge(void *arg) {
	char ret[1005];
	char *fpath = (char*)arg;
	dp = opendir(fpath);
	while ((de = readdir(dp)) != NULL) {
		struct stat st;
		char tmppath[1005];
		strcpy(tmppath, fpath);
		strcat(tmppath, "/");
		strcat(tmppath, de->d_name);
		stat(tmppath, &st);
		if (S_ISREG(st.st_mode) == 0)
			continue;
		if (strlen(de->d_name) < 5)
			continue;
		int sz = strlen(de->d_name);
		if (de->d_name[strlen - 1] != '0' || de->d_name[strlen - 2] != '0' || de->d_name[strlen - 3] != '0'
			|| de->d_name[strlen - 4] != '.')
			continue;
		pthread_create(&(tid[0]), NULL, &merge, tmppath);
	}
}

static int xmp_create(const char *path, mode_t mode, struct fuse_file_info *fi)
{
	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum create: %s---------------\n", path_temp);
	
	if (strstr(path_temp, "/YOUTUBER") != NULL) {
		mode = 0000640;
		//strcat(path_temp, ".iz1");
	}

	enkripsi(path_temp);
	
	printf("--------------path_temp setelah create: %s---------------\n", path_temp);

	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if create: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path dalam else create: %s---------------\n", fpath);
	}

	// printf("FPATH akhir: %s\n", fpath);
	// if (strstr(path, "/YOUTUBER") != NULL) {
	// 	char newname[1005];
	// 	strcpy(newname, fpath);
	// 	char ext[] = ".iz1";
	// 	enkripsi(ext);
	// 	strcat(newname, ext);
	// 	// strcpy(fpath, )
	// 	// printf("%s\n", newname);
	// 	// rename(fpath, newname);
	// }
	memset(temp_path,0,sizeof(temp_path));
	strcpy(temp_path,path);
	
	int fd;
	
	fd = creat(fpath, mode);
	if (fd == -1)
		return -errno;
	close(fd);
	flag = 0;
	int err = pthread_create(&(tid[0]), NULL, &renamefile, fpath);
	if (err != 0)
		printf("\n ===***can't create thread : [%s]",strerror(err));
	else 
		printf("\n ===***create thread success\n");
	

	return 0;
}

static int xmp_utimens(const char *path, const struct timespec ts[2])
{
	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum readdir: %s---------------\n", path_temp);
	
	enkripsi(path_temp);
	
	printf("--------------path_temp setelah readdir: %s---------------\n", path_temp);
	
	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if readdir: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path1 dalam else readdir: %s---------------\n", fpath);
	}

	int res;

	/* don't use utime/utimes since they follow symlinks */
	res = utimensat(0, fpath, ts, AT_SYMLINK_NOFOLLOW);
	flag = 1;
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_chmod(const char *path, mode_t mode)
{
	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum chmod: %s---------------\n", path_temp);
	

	int sz = strlen(path_temp);
	if (strstr(path_temp, "/YOUTUBER/") != NULL && path_temp[sz - 1] == '1' 
		&& path_temp[sz - 2] == 'z' && path_temp[sz - 3] == 'i' && path_temp[sz - 4] == '.') {
    	printf("File ekstensi iz1 tidak boleh diubah permissionnya.\n");
    	return -1;
	}
	// if (strstr(path_temp, "/YOUTUBER") != NULL && strstr(path_temp,".iz1") != NULL) {
 //    	
	// }

	enkripsi(path_temp);
	
	printf("--------------path_temp setelah chmod: %s---------------\n", path_temp);

	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if chmod: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path dalam else chmod: %s---------------\n", fpath);
	}

	int res;

	res = chmod(fpath, mode);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_chown(const char *path, uid_t uid, gid_t gid)
{
	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum readdir: %s---------------\n", path_temp);
	
	enkripsi(path_temp);
	
	printf("--------------path_temp setelah readdir: %s---------------\n", path_temp);
	
	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if readdir: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path1 dalam else readdir: %s---------------\n", fpath);
	}

	int res;

	res = lchown(fpath, uid, gid);
	if (res == -1)
		return -errno;

	return 0;
}


static int xmp_truncate(const char *path, off_t size)
{
	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum readdir: %s---------------\n", path_temp);
	
	enkripsi(path_temp);
	
	printf("--------------path_temp setelah readdir: %s---------------\n", path_temp);
	
	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if readdir: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path1 dalam else readdir: %s---------------\n", fpath);
	}

	int res;

	res = truncate(fpath, size);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_unlink(const char *path)
{
	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum readdir: %s---------------\n", path_temp);
	
	enkripsi(path_temp);
	
	printf("--------------path_temp setelah readdir: %s---------------\n", path_temp);
	
	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if readdir: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path1 dalam else readdir: %s---------------\n", fpath);
	}

	int res;

	res = unlink(fpath);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_rmdir(const char *path)
{
	char fpath[1000],path_temp[1000];
	
	strcpy(path_temp,path);
	printf("--------------path_temp sebelum rmdir: %s---------------\n", path_temp);
	
	enkripsi(path_temp);
	
	printf("--------------path_temp setelah rmdir: %s---------------\n", path_temp);

	if(strcmp(path_temp,"/") == 0)
	{
		sprintf(fpath,"%s",dirpath);
		printf("--------------path dalam if rmdir: %s---------------\n", fpath);
	}
	else{
		sprintf(fpath, "%s%s",dirpath,path_temp);
		printf("--------------path dalam else rmdir: %s---------------\n", fpath);
	}

	int res;

	res = rmdir(fpath);
	if (res == -1)
		return -errno;

	return 0;
}

	// void *xmp_init(struct fuse_conn_info *conn) {

	// }

	// void xmp_destroy(void*) {

	// }


static struct fuse_operations xmp_oper = {
	.getattr	= xmp_getattr,
	.readdir	= xmp_readdir,
	.mkdir		= xmp_mkdir,
	.read		= xmp_read,
	.write		= xmp_write,
	.create     = xmp_create,
	.utimens	= xmp_utimens,
	.chmod		= xmp_chmod,
	.chown		= xmp_chown,
	.truncate	= xmp_truncate,
	.unlink		= xmp_unlink,
	.rmdir		= xmp_rmdir,
	// .init		= xmp_init,
	// .destroy	= xmp_destroy,
};

int main(int argc, char *argv[])
{
	scanf("%d",&key);
	umask(0);
	return fuse_main(argc, argv, &xmp_oper, NULL);
}

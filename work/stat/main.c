// #include <stdio.h>

// int main() {
//     for (int i = 1; i < 256; i++) {
//         printf("    1.1.1.%d - E8:EB:D3:22:1F:31\n", i);
//     }
//     for (int i = 1; i < 256; i++) {
//         printf("    2.2.2.%d - 10:70:FD:79:CF:65\n", i);
//     }
// }


// #include <stdio.h>
// #include <mntent.h>
// #include <string.h>

// int main() {
//     const char *file_path = "/dev";
//     FILE *mounts;
//     struct mntent *ent;
//     char *fs_type = NULL;

//     mounts = setmntent("/proc/mounts", "r");
//     if (mounts == NULL) {
//         perror("setmntent");
//         return 1;
//     }

//     while ((ent = getmntent(mounts)) != NULL) {
//         if (strcmp(file_path, ent->mnt_dir) == 0) {
//             fs_type = strdup(ent->mnt_type);
//             break;
//         }
//     }

//     endmntent(mounts);

//     if (fs_type != NULL) {
//         printf("File system type: %s\n", fs_type);
//     } else {
//         printf("Failed to determine file system type\n");
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/vfs.h>

char *get_fs_type(unsigned long fs_type) {
    switch (fs_type) {
        case 0x01021994:
            return "tmpfs";
        case 0x958458f6:
            return "hugetlbfs";
        // Add more cases for other file system types if needed
        default:
            return "other";
    }
}

int main() {
    const char *filename = "/dev/hugepages"; // 替换为你要获取文件系统信息的文件路径

    struct statfs fs_stat;
    if (statfs(filename, &fs_stat)) {
        perror("statfs");
        exit(EXIT_FAILURE);
    }

    printf("File System Type: %s\n", get_fs_type(fs_stat.f_type));

    return 0;
}




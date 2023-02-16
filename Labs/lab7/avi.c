#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#define OFFSET 32

int main(int argc, char **argv) {
    int avi_file;
    int num_frames, time_scale, data_rate, width, height;
    float fps, time;

    assert(argc == 2);

    if((avi_file = open(argv[1], O_RDONLY)) < 0) {
        perror(argv[1]);
        return 1;
    }

    lseek(avi_file, OFFSET, SEEK_SET);     /* Skip the first 32 bytes */
    lseek(avi_file, 16, SEEK_CUR);         /* Skip 4 integers */
    
    read(avi_file, (void*)&num_frames, 4); /* Read 1 integer which is the total number of frames */
    lseek(avi_file, 12, SEEK_CUR);         /* Skip 3 integers */
    
    read(avi_file, (void*)&width, 4);      /* Read 1 integer -> width */
    read(avi_file, (void*)&height, 4);     /* Read 1 integer -> height */
    read(avi_file, (void*)&time_scale, 4); /* Read 1 integer -> time_scale */
    read(avi_file, (void*)&data_rate, 4);  /* Read 1 integer -> data rate */

    close(avi_file);

    /* According to avi specifications, to calculate the frame rate we needd the data rate and time scale */
    fps = (float)data_rate / time_scale;
    time = num_frames / fps;

    printf("Info for video file `%s`: \n"
           "    image size: %d x %d pixels\n"
           "    frame rate: %.2f fps\n"
           "    durations: %.2f sec\n",
           argv[1],
           width, height,
           fps,
           time
    );

    return 0;
}

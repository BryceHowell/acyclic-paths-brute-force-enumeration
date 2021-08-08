#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
 
struct point {
    char x,y;
};
 
 
// check array of points for overlap with new point
 
int check_end( struct point * path, int length) {
    for (int i=0; i<length-1; i++) {
        if (path[i].x==path[length-1].x && path[i].y==path[length-1].y) return 1;
        }
    return 0;
    }
    
// return a list with the next point added
struct point * add_point(struct point * path, int length, int dir) {
    struct point * next=(struct point *)malloc((length+1)*sizeof(struct point));
    memcpy(next,path,sizeof(struct point)*length);
    next[length].x=next[length-1].x;
    next[length].y=next[length-1].y;
    if (dir==0) next[length].x++;
    if (dir==1) next[length].y++;
    if (dir==2) next[length].x--;
    if (dir==3) next[length].y--;
    return next;
    }
    
 
struct point ** list;
struct point ** next;
 
int length=1;
int next_size,list_size;
 
// first list is (0,0)
 
// allocate 4*list_size ptrs
// for each path in list
//    for each dir
//        add_point
//       if check_end deallocate new path else save in next and increase next_size
// switch next and list, deallocate all in next, then next itself
// increment length, reset Next_size to 0
 
 
int stage() {
    next=(struct point **)malloc(4*list_size*sizeof(struct point *));
    next_size=0;    
    for (int i=0; i<list_size; i++) {
        for (int dir=0; dir<4; dir++) {
            struct point * path=add_point(list[i],length,dir);
            if (check_end(path,length+1)) free(path); else { next[next_size]=path; next_size++;}
            }
    
        }
    struct point ** temp=list;
    list=next; next=temp;
    int temp_size=list_size;
    list_size=next_size; next_size=temp_size;
    for (int i=0; i<next_size; i++) {
        free(next[i]);
        }
    free(next);
    length++;
    return list_size;
    }
 
    
int main(int argc, char *argv[]) {
    int max_length=24;
    if (argc==2) sscanf(argv[1],"%d",&max_length);
    list=(struct point **)malloc(sizeof(struct point *));
    list[0]=(struct point *)malloc(sizeof(struct point));
    list[0][0].x=0; list[0][0].y=0;
    list_size=1;
    for (int i=0; i<max_length; i++)
        printf("%d paths of length %d\n",stage(),length);
    }
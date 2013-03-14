#ifndef _SITE_MARKER_H
#define _SITE_MARKER_H
#define SITE_GROUP_CNT 10
typedef int abool;
#define S_TRUE  1
#define S_FALSE 0
#define S_NULL 0

typedef void* (*nextsite)(void*)  nextsite_t;


typedef struct st_groupInfo
{
    int eleCnt;
    nextsite_t fnext;
    char* name;
    void** datas;
}groupInfo;



typedef struct st_siteMarker
{
    int gint; //group cnt
    groupInfo ginfo[MARKER_GROUP_CNT];
    
}siteMarker;

siteMarker* siteMarker_init();

abool siteMarker_save_site(siteMarker* marker,
                             char*name, void* array, int cnt,
                             nextsite_t fnext);

void* siteMarker_index_site(siteMarker* marker,
                             char*name, int index);

void* siteMarker_clean(siteMarker* marker, char*name);


int siteMarker_destroy(siteMarker* marker);

#endif

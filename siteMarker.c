siteMarker* siteMarker_init()
{
    siteMarker* lp_site_marker = (siteMarker*)malloc(sizeof(siteMarker));
    memset(lp_site_marker, 0, sizeof(siteMarker));
    return lp_site_marker;
}

abool siteMarker_save_site(siteMarker* marker,
                             char*name, void* array, int cnt,
                             nextsite_t fnext)
{
    int i = 0;

    while(i != MARKER_GROUP_CNT)
    {
        if(marker->ginfo[i]->name == S_NULL)
        {
            marker->ginfo[i]->name = strdup(name);
            marker->ginfo[i]->fnext = fnext;
            marker->ginfo[i]->eleCnt = cnt;
            marker->ginfo[i]->datas = (void**)malloc(sizeof(void*) * cnt);
            int j = 0;
            while (j != cnt)
            {
                marker->ginfo[i]->datas[j] = array;
                array = fnext(array);
                j++
            }
            return S_TRUE;
        }
        
        i++;
    }
    return S_FALSE;
}

void* siteMarker_index_site(siteMarker* marker,
                             char*name, int index)
{
    
}

void* siteMarker_clean(siteMarker* marker, char*name)
{
    
}


int siteMarker_destroy(siteMarker* marker)
{
    
}



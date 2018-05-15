//
//  sysUtils.m
//  encodePng
//
//  Created by vega－001 on 14/05/2018.
//  Copyright © 2018 vega－001. All rights reserved.
//

#import "sysUtils.h"

std::string getDir()
{
    char buf[0];
    uint32_t size = 0;
    int res = _NSGetExecutablePath(buf,&size);
    
    char* path = (char*)malloc(size+1);
    path[size] = 0;
    res = _NSGetExecutablePath(path,&size);
    
    char* p = strrchr(path, '/');
    *p = 0;
    std::string pathTemp;
    pathTemp.append(path);
    free(path);
    return pathTemp;
}

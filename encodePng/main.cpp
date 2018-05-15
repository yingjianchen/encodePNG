//
//  main.cpp
//  encodePng
//
//  Created by vega－001 on 14/05/2018.
//  Copyright © 2018 vega－001. All rights reserved.
//

#include <iostream>
#include "Classes/Files.h"
#include "Classes/Encrypt.h"

/**
 * 加密方法：
 * 将本程序放置在需要加密的文件夹根目录，运行并输入密钥和新扩展名。
 */

const aes_key SECRET_KEY = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

int main(int argc, char** argv)
{
    std::cout << "=============== argc = " << argc << std::endl;
    std::cout << ">> 请将本程序放置在需要加密的文件夹根目录，  <<" << std::endl;
    std::cout << ">> 输入密钥和扩展名后，将对PNG图片进行加密， <<" << std::endl;
    std::cout << ">> 输出文件在源目录下，扩展名为输入的扩展名。<<" << std::endl;
    std::cout << "===============================================" << std::endl;
    
    // 输入密钥
    aes_key key = SECRET_KEY;
//    std::cout << std::endl << ">> 请输入16位密钥（AES）：" << std::endl;
//    std::cin.get((char *)&key[0], key.size());
    
    // 输入扩展名
    std::string exten = "";
//    std::cout << std::endl << ">> 请输入新扩展名（.fox）：" << std::endl;
//    std::cin >> exten;
    
    // 寻找所有png图片
    std::vector<std::string> pngfiles;
    auto all_files = path::walk(path::curdir());
    
    for (auto filename : all_files)
    {
        if (path::splitext(filename)[1] == ".png")
        {
            pngfiles.push_back(filename);
        }
    }
    
    pngfiles.clear();
//    pngfiles.push_back("/Users/vega-001/Documents/test/instance_icon/1001.png");
//    pngfiles.push_back("/Users/vega-001/Documents/test/instance_icon/1002.png");
//
    if (argc != 2)
    {
        std::cout << ">> 没有传入需要加密的png, 程序退出" << std::endl;
        return 0;
    }
    
    std::string name(argv[1]);
    pngfiles.push_back(name);
    
    // 取相对路径
//    auto absolute_path = path::curdir() + "\\";
//    for (auto &filename : pngfiles)
//    {
//        filename = filename.substr(absolute_path.size(), filename.size());
//    }
    
    std::cout << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << ">> 加密开始..." << std::endl << std::endl;
    
    // 图片加密操作
    EncryptPNG(pngfiles, key, exten);
    
    std::cout << std::endl;
    std::cout << ">> 加密已完成" << std::endl;
    std::cout << "===============================================" << std::endl << std::endl;
    
    system("pause");
    
    return 0;
}

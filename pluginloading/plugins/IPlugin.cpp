//
// Created by Yannick on 27.02.2017.
//

#if _WIN32 || _WIN64
#include <typeinfo.h>
#else
#include <typeinfo>
#endif


#include "IPlugin.h"


IPlugin::~IPlugin() {}

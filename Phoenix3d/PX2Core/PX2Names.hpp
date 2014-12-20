/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Names.hpp
*
*/

#ifndef PX2NAMES_HPP
#define PX2NAMES_HPP

#include "PX2CorePre.hpp"

//----------------------------------------------------------------------------
#define PX2_DECLARE_NAMES \
public: \
    virtual Object* GetObjectByName (const std::string& name); \
    virtual void GetAllObjectsByName (const std::string& name, \
        std::vector<Object*>& objects)
//----------------------------------------------------------------------------
#define PX2_IMPLEMENT_DEFAULT_NAMES(baseclassname, classname) \
Object* classname::GetObjectByName (const std::string& name) \
{ \
    return baseclassname::GetObjectByName(name); \
} \
\
void classname::GetAllObjectsByName (const std::string& name, \
    std::vector<Object*>& objects) \
{ \
    baseclassname::GetAllObjectsByName(name, objects); \
}
//----------------------------------------------------------------------------
#define PX2_GET_OBJECT_BY_NAME(source, name, found) \
if (source) \
{ \
    found = source->GetObjectByName(name); \
    if (found) \
    { \
        return found; \
    } \
}
//----------------------------------------------------------------------------
#define PX2_GET_ALL_OBJECTS_BY_NAME(source, name, objects) \
if (source) \
{ \
    source->GetAllObjectsByName(name, objects); \
}
//----------------------------------------------------------------------------

#endif
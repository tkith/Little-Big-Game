#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <unordered_map>
#include <string>

using namespace std;

template<typename Resource>
class ResourceManager
{
    public:
        ResourceManager(const string& f) { this->folder = f; };

        /** Add a resource **/
        void Add(const string& name)
        {
            Resource r;

            if (!r.loadFromFile(GetPath(name)))
            {
                Resource fail;
                fail.loadFromFile(GetPath(name) + "_fail");
                resources.insert(make_pair(name, fail));
            }
            else
            {
                resources.insert(make_pair(name, r));
            }
        }

        /** Get a resource **/
        const Resource& Get(const string& name)
        {
            /** If the resource can't be found, add it **/
            if (resources.find(name) == resources.end())
            {
                Add(name);
            }

            return resources.at(name);
        }

    private:
        string GetPath(const string& name)
        {
            return folder + "/" + name;
        }

        string folder;
        unordered_map<string, Resource> resources;
};

#endif // RESOURCEMANAGER_H

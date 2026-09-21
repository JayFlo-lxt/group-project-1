#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>

class Resource {
public:
    Resource();
    Resource(const std::string& id, const std:: string& name,
              const std::string& type, bool available);
    
    
    std:: string getResourceID() const;
    std:: string getName() const;
    std:: string getType() const;
    bool isAvailable() const;

    void setAvailable(bool status);

    void display() const;

private:
    std::string resourceID;
    std::string name;
    std::string type;
    bool availabilityStatus;
    };


std::vector<Resource> loadResourcesFromFile(const std::string& filename);

void displayAllResources(const std::vector<Resource>& resources);


bool displayResourceAvailability(const std::vector<Resource>& resources,
                                  const std::string& resourceID);

#endif 
#include "Resource.h"
#include <iostream>
#include <fstream>
#include <sstream>

Resource::Resource()
    : resourceID(""), name(""), type(""), availabilityStatus(false) {}

Resource::Resource(const std::string& id, const std::string& name,
                   const std::string& type, bool available) 
    : resourceID(id), name(name), type(type), availabilityStatus(available) {}

std::string Resource::getResourceID() const { return resourceID; }
std::string Resource::getName() const { return name; }
std::string Resource::getType() const { return type; }
bool Resource::isAvailable() const { return availabilityStatus; }

void Resource::setAvailable(bool status) { availabilityStatus = status; }

 
void Resource::display() const {
    std::cout << "ID: " << resourceID
              << " | Name: " << name
              << " | Type: " << type
              << " | Available: " << (availabilityStatus ? "Yes" : "No")
              << std::endl;
}
 
std::vector<Resource> loadResourcesFromFile(const std::string& filename) {
    std::vector<Resource> resources;
    std::ifstream file(filename);
 
    if (!file.is_open()) {
        std::cerr << "Error: could not open resource file " << filename << std::endl;
        return resources; 
    }
 
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue; 
 
        std::stringstream ss(line);
        std::string id, name, type, availStr;
 
        
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, availStr, ',');
 
        bool available = (availStr == "1"); 
        resources.push_back(Resource(id, name, type, available));
    }
 
    file.close();
    return resources;
}
 
void displayAllResources(const std::vector<Resource>& resources) {
    if (resources.empty()) {
        std::cout << "No resources loaded." << std::endl;
        return;
    }
    for (const auto& r : resources) {
        r.display();
    }
}
 
bool displayResourceAvailability(const std::vector<Resource>& resources,
                                  const std::string& resourceID) {
    for (const auto& r : resources) {
        if (r.getResourceID() == resourceID) {
            std::cout << r.getName() << " (" << resourceID << ") is "
                      << (r.isAvailable() ? "available." : "not available.")
                      << std::endl;
            return true;
        }
    }
    std::cout << "Resource ID " << resourceID << " not found." << std::endl;
    return false;
}
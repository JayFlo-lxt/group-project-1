#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>

// Represents a single campus resource (laptop, study room, calculator, etc.)
class Resource {
public:
    Resource();
    Resource(const std::string& id, const std:: string& name,
              const std::string& type, bool available);
    
    // Getters
    std:: string getResourceID() const;
    std:: string getName() const;
    std:: string getType() const;
    bool isAvailable() const;

    // Setters
    void setAvailable(bool status);

    // Prints one resource's info to the console
    void display() const;

private:
    std::string resourceID;
    std::string name;
    std::string type;
    bool availabilityStatus;
    };

// Reads a data file and returns a vector of Resource objects
//format: ResourceID,Name,Type,AvailabilityStatus(0/1)
std::vector<Resource> loadResourcesFromFile(const std::string& filename);

// Prints every resource in the vector 
void displayAllResources(const std::vector<Resource>& resources);

// Looks up a resource by ID and prints its availability
// Returns false if the resource is not found.
bool displayResourceAvailability(const std::vector<Resource>& resources,
                                  const std::string& resourceID);

#endif // RESOURCE_H
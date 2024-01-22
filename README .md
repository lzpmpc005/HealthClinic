# Health Clinic Management Application

## 1. INTRODUCTION:
   This health clinic management application is automated and utilizes the Crow package for handling http requests, as well as sqlite3 for data management. It includes a register function for patients and doctors, using patient_id/doctor_id/Controllers. Additionally, users can schedule appointments with a necessary doctors, and doctors can record patients' medical histories. All of this data can be retrieved by sending a GET request. The application is developed in C++ using Windows OS, and Linux operating systems. However, for advanced functionality of application, it has been developed with the server.
![introduction](/img/clinicapp.png)


## 2. Installation and Running the Application
	 Set up your enviroment: it could be 
cmd
Visual Studio Code.
Git.
NodeJS and npm.
Express.js.
React.

	Install and run Sqlite/MySQL for the work with the Database of Patients, Doctors and Treatment (Medical Issues and solving these deseases)
	Install and run Crow (C++ Framework - an easy-to-use framework for building HTTP or Websocket web services)

 ## 3. FEATURES
![introduction](/img/weeklyclinic.png)
 # (1) Register patient        
http://localhost:18080/patient/register        
request method: POST        
request body:        
{    
    "patient_id": "Randomly UUID choice"
    "name": "String type of entering an information (A-Z)", 
    "age": "Int type of entered information (0-9) ",
    "gender": "Male/Female"
    "address": "String and int type of entering an information (A-Z/0-9) ",        
    "phone": "Int type of entered information (0-9)"     
    "medical_history": "String and int type of entering an information (A-Z/0-9),
    "count_visits": "Int type of entered information (0-9)"
}        

# (2) Retrieve patients        
http://localhost:18080/patient        
request method: GET

# (3) Register doctor        
http://localhost:18080/doctor/register       
request method: POST        
request body:        
{  
    "doctor_id": "Randomly UUID choice"
    "name": "String type of entering an information (A-Z)",        
    "specialization": "String type of entering an information (A-Z)",
    "address": "String and int type of entering an information (A-Z/0-9)"
    "phone": "Int type of entered information (0-9)"
}        

# (4) Retrieve doctors        
http://localhost:18080/doctor       
request method: GET

# (5) Make appointment        
http://localhost:18080/patient/appointment        
request method: POST        
request body:        
{        
    "patient_id": Randomly UUID choice,        
    "doctor_id": Randomly UUID choice,        
    "date":"DD-MM-YYYY",        
    "time": "7:00-19:00, only direct time(10.00/15.00, NOT 14.35)"        
}        

# (6) Retrieve appointments        
http://localhost:18080/appointment      
request method: GET 


# (7) Record medical history        
http://localhost:18080/patient/medical_history        
request method: POST             
request body:        
{    

"id", columnTypes::INT, true,
"patient_id", columnTypes::TEXT, false, true, "patients", "patient_ID",
"doctor_id", columnTypes::INT, false, true, "doctors", "id",
"prescription", columnTypes::TEXT,
"date", columnTypes::TEXT,
}        

# (8) Searching to retrieve patient`s medical history
http://localhost:18080/medical_history/ID     
request method: GET 

# (8) Retrieve medical history        
Medical history by patient_id cosists of Controller, searching by 1 feature (gender/age/id)
http://localhost:18080/medical_history                
request method: GET
{
"patient_id": Randomly UUID Choice
}

# (9) Implementing a procedure to record prescriptions associated with a patient ID
http://localhost:18080/doctor/prescribe       
request method: POST             
request body:        
{    
"patient_id", columnTypes::TEXT, false, true, "patients", "patient_ID",
"doctor_id", columnTypes::INT, false, true, "doctors", "id",
"prescription", columnTypes::TEXT
}        

# (10) Updating medical records after each patient visit

After each appointment count_visits becomes greater for 1 point
request body:
{
	"id", columnTypes::INT, true,
 	"name", columnTypes::TEXT,
        "age", columnTypes::INT,
        "gender", columnTypes::TEXT,
        "address", columnTypes::TEXT,
        "phone", columnTypes::TEXT,
        "medical_history", columnTypes::TEXT,
        "count_visits", columnTypes::INT,
        "patient_ID", columnTypes::TEXT
}

# (11) New function:patients can chose their health insurance

This 'insurance function' is designed to manage patient's insurance.
![introduction](/img/insurance_sequence.png)
## New Feature: Insurance Management

### Overview

This feature allows patients to choose their insurance type and track the status of insurance claims. It includes the following functionalities:

1. **Choose Insurance**
   - Route: `/patient/choose_insurance`
   - Method: POST
   - Parameters:
     - `patient_id` (string): ID of the patient
     - `insurance_type` (string): Chosen insurance type (e.g., "public", "private", "none")
   - Description: Allows patients to select their insurance type.

2. **Submit Insurance Claim**
   - Route: `/patient/submit_claim`
   - Method: POST
   - Parameters:
     - `patient_id` (string): ID of the patient
   - Description: Allows patients to submit an insurance claim.

3. **Review Insurance Claim**
   - Route: `/patient/review_claim`
   - Method: POST
   - Parameters:
     - `patient_id` (string): ID of the patient
   - Description: Allows patients to review the status of their insurance claim.

4. **Approve Insurance Claim**
   - Route: `/patient/approve_claim`
   - Method: POST
   - Parameters:
     - `patient_id` (string): ID of the patient
   - Description: Allows patients to approve the outcome of their insurance claim.

### How to Use

1. **Choosing Insurance Type**
   - Send a POST request to `/patient/choose_insurance` with the patient's ID and chosen insurance type.

   Example:
   ```json
   {
     "patient_id": "123456",
     "insurance_type": "private"
   }

2. **Submitting an Insurance Claim**

   - Send a POST request to `/patient/submit_claim` with the patient's ID.
  
    Example:
    ```json
    {
      "patient_id": "123456"
    }
3. **Reviewing Insurance Claim**

   - Send a POST request to /patient/review_claim with the patient's ID.
 
   Example:
    ```json
    {
     "patient_id": "123456"
    }
4. **Approving Insurance Claim**
   - Send a POST request to /patient/approve_claim with the patient's ID.

    Example:
    ```json
    {
     "patient_id": "123456"
    }

### Notes

1. **Ensure valid patient IDs and insurance types are used for the requests.**
2. **Monitor the response messages to track the success or failure of each operation.**

**Feel free to contact the development team for any assistance or issues related to the new insurance management feature.**

# (12) New Feature: Inventory Monitoring and Alert System

The system introduces a module called StockChecker responsible for periodic checks on specific item inventories and issuing warnings when the inventory falls below a set threshold. 
The key functionalities include:




### Overview

This feature allows patients to choose their insurance type and track the status of insurance claims. It includes the following functionalities:

1. **Expansion of InventoryManager:**
    A class named InventoryManager has been introduced for inventory management, allowing the initialization of different item quantities with the addItem method.
   ```cpp
    {
    class InventoryManager {
    public:
    void addItem(const std::string& itemName, int initialQuantity);
    // ... other methods
     };
   }

2. **StockChecker Module:**
   The StockChecker module has been introduced, which checks the inventory level of specific items at regular intervals in a separate thread. When the inventory falls below the predefined threshold, the system outputs a warning.
   ```cpp
   class StockChecker {
   public:
    StockChecker(InventoryManager& manager, const std::string& itemName, int alertThreshold);
    void startChecking();
    // ... other methods
   };
3. **Launching StockChecker in the Main Application:**
    In the main function of the main application, the InventoryManager is initialized, and initial stock quantities are added. Subsequently, a new thread is created to initiate the StockChecker for monitoring the inventory of specific items.
    ```cpp
    int main() {
    // ... initialize other components

    InventoryManager inventoryManager;
    inventoryManager.addItem("vaccine", 50);

    // Start inventory monitoring in a new thread
    std::thread stockCheckerThread([&]() {
        StockChecker stockChecker(inventoryManager, "vaccine", 10);
        stockChecker.startChecking();
    });

    // ... start other services

    return 0;
   }
### Advantages:
1. **eal-time monitoring of inventory levels allows for prompt identification of low inventory issues, helping to prevent business disruptions due to item shortages.**
2. **Enhances the stability and reliability of business operations, especially for critical items like vaccines, by ensuring timely control of inventory levels.**
   
### Use Cases:
1. **When the inventory of specific items (e.g., vaccines) falls below the defined threshold, the system outputs a warning message on the console, reminding staff to procure or redistribute items promptly.**

### Considerations:
1. **The inventory monitoring module needs to run in the background to ensure periodic checks on inventory levels.**
2. **Setting inventory threshold values should be based on actual business scenarios to ensure timely and accurate warnings.**

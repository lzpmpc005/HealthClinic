#include "crow.h"
#include "crow/app.h"
#include "crow/task_timer.h"
#include <iostream>
#include <string>
#include <memory>

#include "patient.repository.hpp"
#include "patient.service.hpp"
#include "patient.controller.hpp"

#include "prescription.repository.hpp"

#include "appointment.repository.hpp"
#include "appointment.service.hpp"

#include "doctor.repository.hpp"
#include "doctor.service.hpp"
#include "doctor.controller.hpp"

#include "insurance.repository.hpp"
#include "insurance.service.hpp"
#include "insurance.controller.hpp"

#include "SqliteORM.hpp"

#include "InventoryManager.hpp"

int main()
{
    crow::SimpleApp app;

    SqliteORM *orm = new SqliteORM();
    orm->connect("clinic.db");
    std::shared_ptr<PatientRepository> patients = std::make_shared<PatientRepository>(orm);
    std::shared_ptr<DoctorRepository> doctors = std::make_shared<DoctorRepository>(orm);
    std::shared_ptr<AppointmentRepository> appointments = std::make_shared<AppointmentRepository>(orm);
    std::shared_ptr<PrescriptionRepository> prescriptions = std::make_shared<PrescriptionRepository>(orm);

    std::shared_ptr<PatientService> patientService = std::make_shared<PatientService>(patients);
    std::shared_ptr<DoctorService> doctorService = std::make_shared<DoctorService>(doctors, patients, prescriptions);
    std::shared_ptr<AppointmentService> appointmentService = std::make_shared<AppointmentService>(appointments);

    std::shared_ptr<PatientController> patientController = std::make_shared<PatientController>(app, patientService, appointmentService);
    std::shared_ptr<DoctorController> doctorController = std::make_shared<DoctorController>(app, doctorService);
    std::shared_ptr<InsuranceRepository> insuranceRepo = std::make_shared<InsuranceRepository>(orm);
    std::shared_ptr<InsuranceService> insuranceService = std::make_shared<InsuranceService>(insuranceRepo);
    std::shared_ptr<InsuranceController> insuranceController = std::make_shared<InsuranceController>(app, insuranceService);

    app.port(18080).multithreaded().run();

    return 0;
}

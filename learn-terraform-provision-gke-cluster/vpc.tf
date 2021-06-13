variable "project_id" {
  description = "project id"
}

variable "region" {
  description = "region"
}

provider "google" {
//  credentials = file("c:/Users/Avigail/cred2.json")
//  service_account= "compute-cred@astral-genre-316321.iam.gserviceaccount.com"

  project = var.project_id
  region  = var.region
}
//resource "google_service_account" "service_account" {
//  account_id   = "compute-cred@astral-genre-316321.iam.gserviceaccount.com"
////  account_id   = "115962661526398265650"
//  display_name = "compute_cred"
//}

# VPC
resource "google_compute_network" "vpc" {
  name                    = "${var.project_id}-vpc"
  auto_create_subnetworks = "false"
}

# Subnet
resource "google_compute_subnetwork" "subnet" {
  name          = "${var.project_id}-subnet"
  region        = var.region
  network       = google_compute_network.vpc.name
  ip_cidr_range = "10.10.0.0/24"
}

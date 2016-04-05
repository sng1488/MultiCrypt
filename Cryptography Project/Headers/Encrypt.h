#ifndef ENCRYPT_H
#define ENCRYPT_H
#include "Headers/IO.h"
#include "Headers/FileIO.h"
#include "Headers/Conversions.h"
#include "Headers/KeyGenerate.h"
#include "Headers/MatrixMath.h"



void encrypt();

void getPathInterface(string&fileName);

void passwordPromptOutput(string fileName, vector<vector<unsigned long long>> key);

#endif
#pragma once
#include "Textures.h"
#include "InputHandler.h"
#include "pch.h"
void questions(Textures*); // function which will call seperately the functions for each question of the questionaire
void flagQuestions(Textures*); // flag handling function for the questions

extern bool flagQuestion[4]; // flags to know on which question tab are we
extern bool flagOptions[4]; // flags for question 1 a),b),c),d) options

extern bool flagTypeHere; // flag to know if the field type here has been pressed

extern string balance; // balance that we enter in the type here field

extern bool flagQuestionOTT[3][3]; // question 2 flags for each option in each subquestion (2-1,2-2,2-3)
extern bool flagShowQuestionaire;

void QuestionOne(Textures*); // question one function
void QuestionTwo(Textures*); // question two function
void QuestionThreeFour(Textures*); // question three and four function which almost work the same
void flagQuestions(Textures*); // flags handle function for questions

extern string getBalance; // balance which we show and use in the dashboard
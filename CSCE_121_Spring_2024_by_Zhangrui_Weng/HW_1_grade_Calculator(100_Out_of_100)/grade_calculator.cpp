
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average, double hw_average, double lw_average,
                   double reading, double engagement, double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string &line, string *category,
                            double *score);

int main() {
  print_instructions();

  // ONLY MAKE CHANGES WHERE THERE IS A TODO

  // TODO(student): declare and initialize variables that you want

  // my own made up variable

  double examGrade = 0.0;
  double finalExamGrade = 0.0;
  double hwGrade = 0.0;
  double engageGrade = 0.0;
  double labWork = 0;
  double readingGrade = 0.0;

  // counting all the occurrence
  int examGradeCount = 0;

  int hwGradeCount = 0;
  int engageGradeCount = 0;
  int labWorkCount = 0;
  int readingGradeCount = 0;

  string line = "";

  //   double sum = 0;

  // read one line from standard input (discards the ending newline character)
  getline(cin, line);
  // read lines until an empty line is read
  while (!line.empty()) {
    string category = "";

    double score = 0;

    get_category_and_score(line, &category, &score);

    // process the grade entry
    if (category == "exam") {
      // TODO(student): process exam score
      // cut down certain part of the string and trim down the space so the exam
      // score can be extracted

      //       sum += score;
      examGrade += score;
      examGradeCount++;

    } else if (category == "final-exam") {
      // TODO(student): process final score
      // cut down certain part of the string and trim down the space so the exam
      // score can be extracted
    
      //    sum += score;
      if (score == 0) {
        finalExamGrade = 0;
      } else {
        finalExamGrade += score;
      }

    } else if (category == "hw") {
      // TODO(student): process hw score

      hwGrade += score;
      //   sum += score;
      hwGradeCount++; // need to fix it later?

    } else if (category == "lw") {
      // TODO(student): process lw score

      labWork += score;
      labWorkCount++;

    } else if (category == "reading") {
      // TODO(student): process reading score

      //    sum += score;
      readingGrade += score;
      readingGradeCount++;

    } else if (category == "engagement") {
      // TODO(student): process engagement score

      //    sum += score;
      engageGrade += score;
      engageGradeCount++;
    } else {
      cout << "ignored invalid input" << endl;
    }

    // get the next line from standard input
    getline(cin, line);
  }

  // TODO(student): compute component averages

  // now i just need to find how to know when there is no final exam score given

  double exam_average = std::max(
      (((examGrade + finalExamGrade) / (examGradeCount + 1))),
      finalExamGrade); // need to some if statement since you have to figure
  double hw_average = (hwGradeCount > 0) ? (hwGrade / hwGradeCount) : 0;
  double lw_average = (labWorkCount > 0) ? ((labWork / labWorkCount) * 100) : 0;
  double reading = (readingGradeCount > 0)
                       ? std::min(readingGrade / readingGradeCount + 15, 100.0)
                       : 0;
  double engagement = (engageGradeCount > 0)
                          ? std::min(engageGrade / engageGradeCount + 15, 100.0)
                          : 0;

  // TODO(student): compute weighted total of components
  double weighted_total =
      ((exam_average * 0.4) + (hw_average * 0.4) + (lw_average * 0.1) +
       (reading * 0.05) + (engagement * 0.05));

  // TODO(student): compute final letter grade
  char final_letter_grade = (weighted_total >= 90.0)   ? 'A'
                            : (weighted_total >= 80.0) ? 'B'
                            : (weighted_total >= 70.0) ? 'C'
                            : (weighted_total >= 60.0) ? 'D'
                                                       : 'F';
  ;

  print_results(exam_average, hw_average, lw_average, reading, engagement,
                weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
  cout << "enter grades as <category> <score>" << endl;
  cout << "  <category> := exam | final-exam | hw | lw | reading | engagement"
       << endl;
  cout << "     <score> := numeric value" << endl;
  cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(const string &line, string *category,
                            double *score) {
  // turn the string into an input stream
  std::istringstream sin(line);

  // read the category (as string) and score (as double) from the stream
  sin >> *category;
  sin >> *score;

  if (sin.fail()) {
    // the stream is in a fail state (something went wrong)
    // clear the flags
    sin.clear();
    // clear the stream buffer (throw away whatever garbage is in there)
    sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // signal that the line was invalid
    *category = "ignore";
  }
}

void print_results(double exam_average, double hw_average, double lw_average,
                   double reading, double engagement, double weighted_total,
                   char final_letter_grade) {
  cout << "summary:" << endl;
  cout << "      exam average: " << exam_average << endl;
  cout << "        hw average: " << hw_average << endl;
  cout << "        lw average: " << lw_average << endl;
  cout << "           reading: " << reading << endl;
  cout << "        engagement: " << engagement << endl;
  cout << "    ---------------" << endl;

  cout << "    weighted total: " << weighted_total << endl;

  cout << "final letter grade: " << final_letter_grade << endl;
}
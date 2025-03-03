Round 1 : Machine Coding


Desing Rating service.
	1) Where Admin can create a survey 
	2) add questions to a survey 
	3) User can take the survey and give responses. 
	4) we should support average rating per survey result 
	5) we should support average rating of a survey. 
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Question {
public:
    int id;
    std::string text;

    Question(int id, const std::string& text) : id(id), text(text) {}
};

class Survey {
public:
    int id;
    std::string name;
    std::vector<Question> questions;

    Survey(int id, const std::string& name) : id(id), name(name) {}

    void addQuestion(const Question& question) {
        questions.push_back(question);
    }
};

class Response {
public:
    int surveyId;
    std::unordered_map<int, int> questionRatings; // questionId -> rating

    Response(int surveyId) : surveyId(surveyId) {}

    void addRating(int questionId, int rating) {
        questionRatings[questionId] = rating;
    }
};

class RatingService {
private:
    std::unordered_map<int, Survey> surveys;
    std::vector<Response> responses;

public:
    void createSurvey(int id, const std::string& name) {
        surveys[id] = Survey(id, name);
    }

    void addQuestionToSurvey(int surveyId, int questionId, const std::string& questionText) {
        if (surveys.find(surveyId) != surveys.end()) {
            surveys[surveyId].addQuestion(Question(questionId, questionText));
        } else {
            std::cout << "Survey not found!" << std::endl;
        }
    }

    void takeSurvey(int surveyId, const std::unordered_map<int, int>& userResponses) {
        if (surveys.find(surveyId) != surveys.end()) {
            Response response(surveyId);
            for (const auto& [questionId, rating] : userResponses) {
                response.addRating(questionId, rating);
            }
            responses.push_back(response);
        } else {
            std::cout << "Survey not found!" << std::endl;
        }
    }

    double getAverageRatingPerSurvey(int surveyId) {
        double totalRating = 0;
        int totalResponses = 0;

        for (const auto& response : responses) {
            if (response.surveyId == surveyId) {
                for (const auto& [questionId, rating] : response.questionRatings) {
                    totalRating += rating;
                    totalResponses++;
                }
            }
        }

        return totalResponses > 0 ? totalRating / totalResponses : 0;
    }

    double getAverageRatingOfSurvey(int surveyId) {
        double totalRating = 0;
        int totalQuestions = 0;

        if (surveys.find(surveyId) != surveys.end()) {
            const Survey& survey = surveys[surveyId];
            for (const auto& question : survey.questions) {
                totalRating += getAverageRatingPerQuestion(surveyId, question.id);
                totalQuestions++;
            }
        }

        return totalQuestions > 0 ? totalRating / totalQuestions : 0;
    }

private:
    double getAverageRatingPerQuestion(int surveyId, int questionId) {
        double totalRating = 0;
        int totalResponses = 0;

        for (const auto& response : responses) {
            if (response.surveyId == surveyId && response.questionRatings.find(questionId) != response.questionRatings.end()) {
                totalRating += response.questionRatings.at(questionId);
                totalResponses++;
            }
        }

        return totalResponses > 0 ? totalRating / totalResponses : 0;
    }
};

int main() {
    RatingService ratingService;

    // Admin creates a survey
    ratingService.createSurvey(1, "Customer Satisfaction Survey");

    // Admin adds questions to the survey
    ratingService.addQuestionToSurvey(1, 1, "How satisfied are you with our service?");
    ratingService.addQuestionToSurvey(1, 2, "How likely are you to recommend us to a friend?");

    // User takes the survey and gives responses
    std::unordered_map<int, int> userResponses = {{1, 5}, {2, 4}};
    ratingService.takeSurvey(1, userResponses);

    // Calculate average rating per survey
    double avgRatingPerSurvey = ratingService.getAverageRatingPerSurvey(1);
    std::cout << "Average Rating Per Survey: " << avgRatingPerSurvey << std::endl;

    // Calculate average rating of the survey
    double avgRatingOfSurvey = ratingService.getAverageRatingOfSurvey(1);
    std::cout << "Average Rating Of Survey: " << avgRatingOfSurvey << std::endl;

    return 0;
}

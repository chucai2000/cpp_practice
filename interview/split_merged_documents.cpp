#include "split_merged_documents.h"

TEST(split_merged_documents, execution)
{
    split_merged_documents::dictionary["i"] = true;
    split_merged_documents::dictionary["want"] = true;
    split_merged_documents::dictionary["to"] = true;
    split_merged_documents::dictionary["go"] = true;
    split_merged_documents::dictionary["home"] = true;
    split_merged_documents::dictionary["tomorrow"] = true;
    split_merged_documents::dictionary["row"] = true;

    std::string sentence = "iwanttogohometomorrow";
    split_merged_documents::Solve(sentence);
}

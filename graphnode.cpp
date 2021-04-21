#include "graphedge.h"
#include "graphnode.h"
#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    // Task 0: Removed line delete _chatBot because it is also called in destructor of chatLogic
    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
// {
//     _childEdges.push_back(edge);
    
// }

// Task 4
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////

// Task 5 removing this 
// void GraphNode::MoveChatbotHere(ChatBot *chatbot)
// {
//     _chatBot = chatbot;
//     _chatBot->SetCurrentNode(this);
// }

// Task 5: overloading movechatbothere to also take the object chatbot
void GraphNode::MoveChatbotHere(ChatBot chatbot){
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // newNode->MoveChatbotHere(_chatBot);
    // _chatBot = nullptr; // invalidate pointer at source

    // Task 5
    newNode->MoveChatbotHere(std::move(_chatBot));
    // _chatBot = nullptr;
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // return _childEdges[index];

    // Task 4
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
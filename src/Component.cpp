#include "../include/Component.hpp"




Component::Component(GameObject& associated) : associated(associated)
{
}


Component::~Component()
{
}

void Component::Update(float dt)
{
    cout << "Component::Update - Atualizando " << endl;
}

void Component::Render()
{

    cout << "render" <<endl;
}




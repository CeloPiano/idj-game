#include "../include/GameObject.hpp"

GameObject::GameObject()
{
  isDead = false;
};

GameObject::~GameObject()
{
  this->components.clear();
}

void GameObject::Update(float dt)
{
  cout << (this->IsDead()) << endl;

  if (this->IsDead())
  {
  cout << "Heere " << this->components[0]->Is("SpriteRenderer") << endl;
    this->components.clear();
  };


  for (auto component : this->components)
  {
    cout << "entrou" << endl;
    component.get()->Update(dt);
  }
}

void GameObject::Render()
{
  for (auto component : this->components)
  {
    component.get()->Render();
  }
}

bool GameObject::IsDead()
{
  return this->isDead;
}

void GameObject::RequestDelete()
{
  this->isDead = true;
}

void GameObject::AddComponent(Component *cpt)
{
  this->components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component *cpt)
{
  for (auto component : this->components)
  {
    if (component.get() == cpt)
    {
      this->components.erase(this->components.begin() + (component.get() - this->components[0].get()));
    }
  }
}

weak_ptr<Component> GameObject::GetComponent(string type)
{
  for (int i = 0; i < this->components.size(); i++)
  {
    if (this->components[i]->Is(type))
    {
      return this->components[i];
    }
  }
  return weak_ptr<Component>();
}

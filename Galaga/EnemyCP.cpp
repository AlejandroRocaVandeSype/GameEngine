#include "EnemyCP.h"
#include "GameObject.h"
#include "CollisionComponent.h"
#include "HealthComponent.h"
#include "Servicealocator.h"
#include "SoundIDs.h"
#include "MoveComponent.h"
#include <iostream>

EnemyCP::EnemyCP(engine::GameObject* pOwner, const std::string& spriteFilePath, const glm::vec3 formationPos, unsigned int health)
	: Component("EnemyCP", pOwner)
	, m_FormationPos { formationPos }
{
	if (pOwner != nullptr)
	{
		pOwner->AddComponent<engine::RenderComponent>(pOwner, spriteFilePath);
		pOwner->AddComponent<HealthComponent>(pOwner, health);
		MoveComponent::Boundaries enemyBoundaries{};  // No boundaries restriction
		pOwner->AddComponent<MoveComponent>(pOwner, 200.f, enemyBoundaries);
		pOwner->AddComponent<engine::CollisionComponent>(pOwner, pOwner->GetComponent<engine::RenderComponent>()->GetTextureSize());
		pOwner->GetComponent<engine::CollisionComponent>()->AddObserver(this);
		pOwner->GetComponent<HealthComponent>()->AddObserver(this);
	
	}
}

EnemyCP::~EnemyCP()
{

}

void EnemyCP::Update(const float )
{


}

void EnemyCP::ReceiveMessage( const std::string&, const std::string& )
{

}

void EnemyCP::OnNotify(engine::GameObject* gameObject, const engine::Event& event)
{
	if (event.IsSameEvent("CollisionWith Player") || event.IsSameEvent("CollisionWith PlayerMissile"))
	{
		auto healthCP = GetOwner()->GetComponent<HealthComponent>();
		if (healthCP != nullptr)
		{
			healthCP->DecrementHealth(1);
		}

		if (event.IsSameEvent("CollisionWith PlayerMissile"))
		{
			// Deactivate the missile
			gameObject->SetIsActive(false);
		}
	}

	if (event.IsSameEvent("GameObjectDied"))
	{
		auto& soundSystem = engine::Servicealocator::Get_Sound_System();
		soundSystem.PlaySound(short(Sounds::enemyDie));
	}
}


glm::vec3 EnemyCP::GetFormationPos() const
{
	return m_FormationPos;
}
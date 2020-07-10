#pragma once

#include "../../GameObject/Public/GameObject.h"
#include "../../Containers/Public/Point2D.h"
#include "../../Containers/Public/Pointers.h"
#include "../../Physics/Public/PhysicsInfo.h"
#include "../../Physics/Collision/Public/AABB.h"
#include "../../Containers/Public/Matrix4.h"
#include "../../HashedString/Public/HashedString.h"
#include "../../Physics/Collision/Public/Collideable.h"
#include "../../External/json.h"

#include <assert.h>
#include <vector>

namespace Engine
{
	namespace ObjectSpawner
	{

		// Spawns a GameObject from a JSON file
		bool SpawnGameObject(const std::string& i_jsonFileName, SmartPtr<GameObject>& o_gameObject);

		// Spawns a Collideable GameObject from a JSON file
		bool SpawnCollideable(const std::string& i_jsonFileName, SmartPtr<Physics::Collideable>& o_collideable);

		// Registers a controller with the ObjectSpawner
		void RegisterController(HashedString i_ControllerName, WeakPtr<GameObject> o_GameObject);

		// Removes a controller from the list
		void RemoveController(HashedString i_ControllerName);

		// Returns the first GameObject with the given controller if possible
		bool GetFirstGameObjectWithController(HashedString i_ControllerName, WeakPtr<GameObject>& o_GameObject);

		// Clears the list of controllers
		void ClearControllers();

	}

	namespace JSONReader
	{

		SmartPtr<GameObject>	JSONToGameObject(nlohmann::json& i_jsonData);

		Physics::AABB			JSONToAABB(nlohmann::json& i_jsonData);

		float					JSONToMass(nlohmann::json& i_jsonData);

		float					JSONToDrag(nlohmann::json& i_jsonData);

		std::string				JSONToTexture(nlohmann::json& i_jsonData);

		std::string				JSONToController(nlohmann::json& i_jsonData);



		static float			GetFloatFromJSON(const nlohmann::json& i_jsonData);

		static std::string		GetStringFromJSON(const nlohmann::json& i_jsonData);

		static Point2D			GetPoint2DFromJSON(const nlohmann::json& i_jsonData);

		static Matrix4			GetMatrix4FromJSON(const nlohmann::json& i_jsonData);



		std::vector<uint8_t>	LoadFile(const std::string& i_fileName);

	}
}
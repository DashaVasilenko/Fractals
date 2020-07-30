#include <cstdio>

#include "camera.h"
#include "inputSystem.h"
//#include <glfw/glfw3.h>
#include <GLFW/glfw3.h>
//#include <math.h>

Camera::Camera(const glm::vec3& position) {
    this->position = position;
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    right = glm::vec3(1.0f, 0.0f, 0.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);

    phi = glm::degrees(atan(position.z/position.x));
    theta = glm::degrees(atan(sqrt(position.x*position.x + position.z*position.z)/position.y));
    r = glm::length(position);
}

glm::mat4 Camera::GetViewMatrix() {
    return glm::mat4(glm::vec4(right, 0.0f), glm::vec4(up, 0.0f), glm::vec4(front, 0.0f), glm::vec4(position, 1.0f));
    //return glm::lookAt(position, position + front, up);
}

void Camera::Update() {
    UpdatePosition(deltaTime);
    UpdateVectors(deltaTime);
}

void Camera::UpdatePosition(const float& delta) {
    //----------------------------old---------------------------------
    /*
    if (InputSystem::keys[GLFW_KEY_W]) {
        position += front*delta*speed;
    }
    if (InputSystem::keys[GLFW_KEY_S]) {
        position += -front*delta*speed;
    }
    if (InputSystem::keys[GLFW_KEY_D]) {
        position += right*delta*speed;
    }
    if (InputSystem::keys[GLFW_KEY_A]) {
        position += -right*delta*speed;
    }
    if (InputSystem::keys[GLFW_KEY_SPACE]) {
        position += up*delta*speed;
    }
    if (InputSystem::keys[GLFW_KEY_LEFT_SHIFT]) {
        position += -up*delta*speed;
    }
    */
    //----------------------------------------------------------------


    
    position += front*delta*speed*(float)InputSystem::scrollOffsetY;
    InputSystem::scrollOffsetY = 0.0;

    if (InputSystem::mouse[LeftButton]) {
        phi += InputSystem::deltaCursPosX*mouse_sense;
        theta += InputSystem::deltaCursPosY*mouse_sense;
        r = glm::length(position);
        
        position.x = r * sin(glm::radians(theta)) * cos(glm::radians(phi));
        position.y = r * cos(glm::radians(theta));
        position.z = r * sin(glm::radians(phi)) * sin(glm::radians(theta));
    }
    InputSystem::deltaCursPosX = 0.0f;
    InputSystem::deltaCursPosY = 0.0f;
    
}

void Camera::UpdateVectors(const float& delta) {

    //----------------------------old---------------------------------
    /*
    if (InputSystem::mouse[LeftButton]) {
        yaw += InputSystem::deltaCursPosX*mouse_sense;
        pitch += InputSystem::deltaCursPosY*mouse_sense;
    
        if (pitch > 89.0f) pitch = 89.0f;
        if (pitch < -89.0f) pitch = -89.0f;
    
        glm::vec3 tmpFront;
        tmpFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        tmpFront.y = sin(glm::radians(pitch));
        tmpFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    
        front = glm::normalize(tmpFront);
        right = glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
        up = glm::normalize(glm::cross(right, front));
    
        InputSystem::deltaCursPosX = 0.0f;
        InputSystem::deltaCursPosY = 0.0f;
    }
    */
    //----------------------------------------------------------------


    front = glm::normalize(-position);
    right = glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
    up = glm::normalize(glm::cross(right, front));

    //fieldOfView = InputSystem::fieldOfView;
} 
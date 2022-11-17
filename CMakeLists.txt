cmake_minimum_required(VERSION 3.17)

project("bomberman" VERSION 0.0.1 LANGUAGES CXX)

###############################################################################
# BUILD DEPENDENCIES
###############################################################################

if (POLICY CMP0072)
    set(OpenGL_GL_PREFERENCE GLVND)
endif()

add_subdirectory(./deps/)

###############################################################################
# BUILD PROJECT
###############################################################################

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(PROJECT_SOURCES
    src/ECS/ECSErrors.cpp
    src/ECS/Core/EntitiesManager.cpp
    src/ECS/Core/System.cpp
    src/RessourcesManager.cpp
    src/ECS/Core/SystemsManager.cpp
    src/ECS/Core/EventsManager.cpp
    src/ECS/Core/Coordinator.cpp
    src/ECS/Components/Animation.cpp
    src/ECS/Components/RenderableText3d.cpp
    src/ECS/Components/RenderableImage2d.cpp
    src/ECS/Components/RenderableImage3d.cpp
    src/ECS/Components/RenderableRelief3d.cpp
    src/ECS/Components/RenderableCubicMap3d.cpp
    src/ECS/Components/RenderableObject3d.cpp
    src/ECS/Components/Music.cpp
    src/ECS/Systems/TransformSystem.cpp
    src/ECS/Systems/CollisionSystem.cpp
    src/ECS/Systems/CameraSystem.cpp
    src/ECS/Systems/AnimationSystem.cpp
    src/ECS/Systems/Text2dRenderSystem.cpp
    src/ECS/Systems/Text3dRenderSystem.cpp
    src/ECS/Systems/Image2dRenderSystem.cpp
    src/ECS/Systems/Image3dRenderSystem.cpp
    src/ECS/Systems/Relief3dRenderSystem.cpp
    src/ECS/Systems/CubicMap3dRenderSystem.cpp
    src/ECS/Systems/Object3dRenderSystem.cpp
    src/ECS/Systems/Relief3dBoundsSystem.cpp
    src/ECS/Systems/CubicMap3dBoundsSystem.cpp
    src/ECS/Systems/Object3dBoundsSystem.cpp
    src/ECS/Systems/MusicSystem.cpp
    src/Game/Room.cpp
    src/MapLoader/Error.cpp
    src/MapLoader/MapLoader.cpp
    src/MapLoader/MapReader.cpp
    src/MapLoader/Map.cpp
    src/MapLoader/MapPart.cpp
    src/MapLoader/Position.cpp
    src/MapLoader/Ground.cpp
    src/MapLoader/Wall.cpp
    src/MapLoader/Box.cpp
    src/MapLoader/APlayer.cpp
    src/MapLoader/KeyBoardPlayer.cpp
    src/MapLoader/AIPlayer.cpp
    src/MapLoader/Bomb.cpp
    src/MapLoader/Fire.cpp
    src/MapLoader/APowerUp.cpp
    src/MapLoader/LifePowerUp.cpp
    src/MapLoader/BombRangePowerUp.cpp
    src/MapLoader/BombNumberPowerUp.cpp
    src/MapLoader/SpeedPowerUp.cpp
    src/Scenes/ScenesManager.cpp
    src/Scenes/MainMenuScene.cpp
    src/Scenes/PlayerScene.cpp
    src/Scenes/IntroScene.cpp
    src/Scenes/SettingsScene.cpp
    src/Scenes/GameScene.cpp
    src/Scenes/EndScene.cpp
    src/Scenes/TutoScene.cpp
    src/Scenes/CreditsScene.cpp
    src/Scenes/MapSelectionScene.cpp
    src/Scenes/PlayerSelectionScene.cpp
    src/Scenes/MultiPlayerSelectionScene.cpp
    src/PlayersManager.cpp
    src/Clock.cpp
    src/Vector.cpp
    src/IndieError.cpp
    src/Window.cpp
    src/Renderer.cpp
    src/HitboxDisplayer.cpp
    src/PointDisplayer.cpp
    src/HUD.cpp
    src/Redirect.cpp
    src/AudioPlayer.cpp
    src/SettingsManager.cpp
    src/FileReader.cpp
    src/Utils.cpp
    )

add_executable(${PROJECT_NAME}
    src/Main.cpp
    ${PROJECT_SOURCES}
    )

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    include/
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    raylib
    fmt::fmt
    nlohmann_json::nlohmann_json
)

###############################################################################
# BUILD TESTS
###############################################################################

set(TESTS_SOURCES
    tests/StartTests.cpp
    tests/CollisionsTests.cpp
    tests/ECSTests.cpp
    tests/GraphicTests.cpp
    tests/StartTests.cpp
    tests/TransformTests.cpp
    tests/UtilsTests.cpp
    tests/PlayersManagerTests.cpp
    tests/RendererTests.cpp
    tests/VectorTests.cpp
    )

add_executable(unit_tests
    ${PROJECT_SOURCES}
    ${TESTS_SOURCES}
    )

target_include_directories(
    unit_tests
    PRIVATE
    include/
)

enable_testing()

target_link_libraries(
    unit_tests
    PRIVATE
    raylib
    fmt::fmt
    nlohmann_json::nlohmann_json
    gtest
    gtest_main
)

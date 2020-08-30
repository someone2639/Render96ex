#ifndef RM_VK_H
#define RM_VK_H

#include "rm_rapi.h"
#include <glad/vulkan.h>

class rm_mesh_vk : public rm_mesh
{
public:
    virtual void preload();
    virtual void activate();
    virtual void deactivate();
    virtual void cleanup();
    virtual void render();
};

class rm_rapi_vk : public rm_rapi
{
public:
    virtual void setWAPI(rm_wapi* wapi);
    virtual bool checkSupport();
    virtual bool init();
    virtual void cleanup();
    virtual rm_mesh* createMesh();
    virtual uint32_t getRequiredWindowFlags();

    friend GLADapiproc vkLoadFunc(const char *name);

private:
    void createVkInstance();
	void createDebugger();
	void selectPhysicalDevice();
	void createLogicalDevice();
	void createSurface();
	void createSwapchain();
	void createRenderPass();
	void createFrames();
	void createSwapImages();
	void createGraphicsPipeline();
	void createCommandPools();
    void recreateSwapchain();
	void cleanupSwapchain();

    PFN_vkGetInstanceProcAddr mVkGetInstanceProcAddr = nullptr;
    rm_wapi* mWAPI = nullptr;

    VkInstance mInstance = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT mDebugMessenger;
};

#endif

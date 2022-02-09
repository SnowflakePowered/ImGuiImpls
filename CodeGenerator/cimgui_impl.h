#include "cimgui.h"
#include "vulkan_core.h"

typedef struct IDirect3DDevice9 IDirect3DDevice9;
typedef struct ID3D10Device ID3D10Device;
typedef struct ID3D11Device ID3D11Device;
typedef struct ID3D11DeviceContext ID3D11DeviceContext;
typedef struct ID3D12Device ID3D12Device;
typedef struct ID3D12DescriptorHeap ID3D12DescriptorHeap;
typedef struct ID3D12GraphicsCommandList ID3D12GraphicsCommandList;
typedef struct D3D12_CPU_DESCRIPTOR_HANDLE D3D12_CPU_DESCRIPTOR_HANDLE;
typedef struct D3D12_GPU_DESCRIPTOR_HANDLE D3D12_GPU_DESCRIPTOR_HANDLE;
typedef struct ImGui_ImplVulkanH_Frame ImGui_ImplVulkanH_Frame;
typedef struct ImGui_ImplVulkanH_Window ImGui_ImplVulkanH_Window;

struct IDirect3DDevice9;

struct ID3D10Device;

struct ID3D11Device;
struct ID3D11DeviceContext;

struct ID3D12Device;
struct ID3D12DescriptorHeap;
struct ID3D12GraphicsCommandList;
struct D3D12_CPU_DESCRIPTOR_HANDLE;
struct D3D12_GPU_DESCRIPTOR_HANDLE;
typedef struct ImGui_ImplVulkan_InitInfo ImGui_ImplVulkan_InitInfo;
struct ImGui_ImplVulkan_InitInfo
{
    VkInstance                      Instance;
    VkPhysicalDevice                PhysicalDevice;
    VkDevice                        Device;
    uint32_t                        QueueFamily;
    VkQueue                         Queue;
    VkPipelineCache                 PipelineCache;
    VkDescriptorPool                DescriptorPool;
    uint32_t                        Subpass;
    uint32_t                        MinImageCount;
    uint32_t                        ImageCount;
    VkSampleCountFlagBits           MSAASamples;
    const VkAllocationCallbacks*    Allocator;
    void                            (*CheckVkResultFn)(VkResult err);
};
struct ImGui_ImplVulkanH_Frame;
struct ImGui_ImplVulkanH_Window;
struct ImGui_ImplVulkanH_Frame
{
    VkCommandPool       CommandPool;
    VkCommandBuffer     CommandBuffer;
    VkFence             Fence;
    VkImage             Backbuffer;
    VkImageView         BackbufferView;
    VkFramebuffer       Framebuffer;
};
typedef struct ImGui_ImplVulkanH_FrameSemaphores ImGui_ImplVulkanH_FrameSemaphores;
struct ImGui_ImplVulkanH_FrameSemaphores
{
    VkSemaphore         ImageAcquiredSemaphore;
    VkSemaphore         RenderCompleteSemaphore;
};
struct ImGui_ImplVulkanH_Window
{
    int                 Width;
    int                 Height;
    VkSwapchainKHR      Swapchain;
    VkSurfaceKHR        Surface;
    VkSurfaceFormatKHR  SurfaceFormat;
    VkPresentModeKHR    PresentMode;
    VkRenderPass        RenderPass;
    VkPipeline          Pipeline;
    bool                ClearEnable;
    VkClearValue        ClearValue;
    uint32_t            FrameIndex;
    uint32_t            ImageCount;
    uint32_t            SemaphoreIndex;
    ImGui_ImplVulkanH_Frame*            Frames;
    ImGui_ImplVulkanH_FrameSemaphores*  FrameSemaphores;
};CIMGUI_API bool ImGui_ImplWin32_Init(void* hwnd);
CIMGUI_API void ImGui_ImplWin32_Shutdown();
CIMGUI_API void ImGui_ImplWin32_NewFrame();
CIMGUI_API void ImGui_ImplWin32_EnableDpiAwareness();
CIMGUI_API float ImGui_ImplWin32_GetDpiScaleForHwnd(void* hwnd);
CIMGUI_API float ImGui_ImplWin32_GetDpiScaleForMonitor(void* monitor);
CIMGUI_API void ImGui_ImplWin32_EnableAlphaCompositing(void* hwnd);
CIMGUI_API bool ImGui_ImplDX9_Init(IDirect3DDevice9* device);
CIMGUI_API void ImGui_ImplDX9_Shutdown();
CIMGUI_API void ImGui_ImplDX9_NewFrame();
CIMGUI_API void ImGui_ImplDX9_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API bool ImGui_ImplDX9_CreateDeviceObjects();
CIMGUI_API void ImGui_ImplDX9_InvalidateDeviceObjects();
CIMGUI_API bool ImGui_ImplDX10_Init(ID3D10Device* device);
CIMGUI_API void ImGui_ImplDX10_Shutdown();
CIMGUI_API void ImGui_ImplDX10_NewFrame();
CIMGUI_API void ImGui_ImplDX10_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API void ImGui_ImplDX10_InvalidateDeviceObjects();
CIMGUI_API bool ImGui_ImplDX10_CreateDeviceObjects();
CIMGUI_API bool ImGui_ImplDX11_Init(ID3D11Device* device,ID3D11DeviceContext* device_context);
CIMGUI_API void ImGui_ImplDX11_Shutdown();
CIMGUI_API void ImGui_ImplDX11_NewFrame();
CIMGUI_API void ImGui_ImplDX11_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API void ImGui_ImplDX11_InvalidateDeviceObjects();
CIMGUI_API bool ImGui_ImplDX11_CreateDeviceObjects();
CIMGUI_API bool ImGui_ImplDX12_Init(ID3D12Device* device,int num_frames_in_flight,DXGI_FORMAT rtv_format,ID3D12DescriptorHeap* cbv_srv_heap,D3D12_CPU_DESCRIPTOR_HANDLE font_srv_cpu_desc_handle,D3D12_GPU_DESCRIPTOR_HANDLE font_srv_gpu_desc_handle);
CIMGUI_API void ImGui_ImplDX12_Shutdown();
CIMGUI_API void ImGui_ImplDX12_NewFrame();
CIMGUI_API void ImGui_ImplDX12_RenderDrawData(ImDrawData* draw_data,ID3D12GraphicsCommandList* graphics_command_list);
CIMGUI_API void ImGui_ImplDX12_InvalidateDeviceObjects();
CIMGUI_API bool ImGui_ImplDX12_CreateDeviceObjects();
CIMGUI_API bool ImGui_ImplOpenGL3_Init(const char* glsl_version);
CIMGUI_API void ImGui_ImplOpenGL3_Shutdown();
CIMGUI_API void ImGui_ImplOpenGL3_NewFrame();
CIMGUI_API void ImGui_ImplOpenGL3_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API bool ImGui_ImplOpenGL3_CreateFontsTexture();
CIMGUI_API void ImGui_ImplOpenGL3_DestroyFontsTexture();
CIMGUI_API bool ImGui_ImplOpenGL3_CreateDeviceObjects();
CIMGUI_API void ImGui_ImplOpenGL3_DestroyDeviceObjects();
CIMGUI_API bool ImGui_ImplOpenGL2_Init();
CIMGUI_API void ImGui_ImplOpenGL2_Shutdown();
CIMGUI_API void ImGui_ImplOpenGL2_NewFrame();
CIMGUI_API void ImGui_ImplOpenGL2_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API bool ImGui_ImplOpenGL2_CreateFontsTexture();
CIMGUI_API void ImGui_ImplOpenGL2_DestroyFontsTexture();
CIMGUI_API bool ImGui_ImplOpenGL2_CreateDeviceObjects();
CIMGUI_API void ImGui_ImplOpenGL2_DestroyDeviceObjects();
CIMGUI_API bool ImGui_ImplVulkan_Init(ImGui_ImplVulkan_InitInfo* info,VkRenderPass render_pass);
CIMGUI_API void ImGui_ImplVulkan_Shutdown();
CIMGUI_API void ImGui_ImplVulkan_NewFrame();
CIMGUI_API void ImGui_ImplVulkan_RenderDrawData(ImDrawData* draw_data,VkCommandBuffer command_buffer,VkPipeline pipeline);
CIMGUI_API bool ImGui_ImplVulkan_CreateFontsTexture(VkCommandBuffer command_buffer);
CIMGUI_API void ImGui_ImplVulkan_DestroyFontUploadObjects();
CIMGUI_API void ImGui_ImplVulkan_SetMinImageCount(uint32_t min_image_count);
CIMGUI_API bool ImGui_ImplVulkan_LoadFunctions(PFN_vkVoidFunction(*loader_func)(const char* function_name,void* user_data),void* user_data);
CIMGUI_API void ImGui_ImplVulkanH_CreateOrResizeWindow(VkInstance instance,VkPhysicalDevice physical_device,VkDevice device,ImGui_ImplVulkanH_Window* wnd,uint32_t queue_family,const VkAllocationCallbacks* allocator,int w,int h,uint32_t min_image_count);
CIMGUI_API void ImGui_ImplVulkanH_DestroyWindow(VkInstance instance,VkDevice device,ImGui_ImplVulkanH_Window* wnd,const VkAllocationCallbacks* allocator);
CIMGUI_API VkSurfaceFormatKHR ImGui_ImplVulkanH_SelectSurfaceFormat(VkPhysicalDevice physical_device,VkSurfaceKHR surface,const VkFormat* request_formats,int request_formats_count,VkColorSpaceKHR request_color_space);
CIMGUI_API VkPresentModeKHR ImGui_ImplVulkanH_SelectPresentMode(VkPhysicalDevice physical_device,VkSurfaceKHR surface,const VkPresentModeKHR* request_modes,int request_modes_count);
CIMGUI_API int ImGui_ImplVulkanH_GetMinImageCountFromPresentMode(VkPresentModeKHR present_mode);

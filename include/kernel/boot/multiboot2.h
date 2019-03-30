#pragma once

#define MULTIBOOT2_HEADER_MAGIC 0xe85250d6
#define MULTIBOOT2_HEADER_ARCHITECTURE 0

#define MULTIBOOT2_TAG_TYPE_END_OF_TAG 0
#define MULTIBOOT2_TAG_TYPE_INFORMATION_REQUEST 1
#define MULTIBOOT2_TAG_TYPE_ADDRESS 2
#define MULTIBOOT2_TAG_TYPE_ENTRY_ADDRESS 3
#define MULTIBOOT2_TAG_TYPE_EFI_I386_ENTRY_ADDRESS 8
#define MULTIBOOT2_TAG_TYPE_EFI_AMD64_ENTRY_ADDRESS 9
#define MULTIBOOT2_TAG_TYPE_FLAGS 4
#define MULTIBOOT2_TAG_TYPE_FRAMEBUFFER 5
#define MULTIBOOT2_TAG_TYPE_MODULE_ALIGNMENT 6
#define MULTIBOOT2_TAG_TYPE_EFI_BOOT_SERVICE 7
#define MULTIBOOT2_TAG_TYPE_RELOCATABLE 10

#define MULTIBOOT2_TAG_FLAG_TAG_OPTIONAL 1

#ifndef ASM_FILE
#include <stdint.h>
namespace Multiboot2 {

struct Header
{
    uint32_t magic;
    uint32_t architecture;
    uint32_t header_length;
    uint32_t checksum;

    bool isValid() const;
};

struct TagHeader
{
    uint16_t type;
    uint16_t flags;
    uint32_t size;
};

struct Tag
{
    Header header;

    bool is_valid() const = 0;
};

struct TagInformationRequest : public Tag
{
    uint32_t * tag_types;

    bool is_valid() const override;
};

struct TagAddress : public Tag
{
    uint32_t header_addr;
    uint32_t load_addr;
    uint32_t load_end_addr;
    uint32_t bss_end_addr;

    bool is_valid() const override;
};

struct TagEntryAddress : public Tag
{
    uint32_t entry_addr;

    bool is_valid() const override;
};

struct TagFlags : public Tag
{
    uint32_t console_flags;

    bool is_valid() const override;
};

struct TagFrameBuffer : public Tag
{
    uint32_t width;
    uint32_t height;
    uint32_t depth;

    bool is_valid() const override;
};

struct TagModuleAlignment : public Tag
{
    bool is_valid() const override;
};

struct TagEFIBootService : public Tag
{
    bool is_valid() const override;
};

struct TagRelocatable  : public Tag
{
    uint32_t min_addr;
    uint32_t max_addr;
    uint32_t align;
    uint32_t preference;

    bool is_valid() const override;
};


}
#endif
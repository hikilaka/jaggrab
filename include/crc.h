#ifndef SYSD_CRC_H
#define SYSD_CRC_H

#pragma once

#include <stddef.h>
#include <stdint.h>

uint32_t crc32(uint32_t crc, const void *buf, size_t size);

#endif // SYSD_CRC_H


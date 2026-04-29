#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.GDI;
#endif

#include "WandX.Win32.Types.h"

// from WinGDI.h
#undef AddFontResource
#undef CopyMetaFile
#undef CreateDC
#undef CreateFontIndirect
#undef CreateFont
#undef CreateIC
#undef CreateMetaFile
#undef CreateScalableFontResource
#undef DeviceCapabilities
#undef EnumFontFamiliesEx
#undef EnumFontFamilies
#undef EnumFonts
#undef GetCharWidth
#undef GetCharWidth32
#undef GetCharWidthFloat
#undef GetCharABCWidths
#undef GetCharABCWidthsFloat
#undef GetGlyphOutline
#undef GetMetaFile
#undef GetOutlineTextMetrics
#undef GetTextExtentPoint
#undef GetTextExtentPoint32
#undef GetTextExtentExPoint
#undef GetCharacterPlacement
#undef GetGlyphIndices
#undef AddFontResourceEx
#undef RemoveFontResourceEx
#undef ResetDC
#undef RemoveFontResource
#undef CopyEnhMetaFile
#undef CreateEnhMetaFile
#undef GetEnhMetaFile
#undef GetEnhMetaFileDescription
#undef GetTextMetrics
#undef StartDoc
#undef GetObject
#undef TextOut
#undef ExtTextOut
#undef PolyTextOut
#undef GetTextFace
#undef GetKerningPairs
#undef GetLogColorSpace
#undef CreateColorSpace
#undef GetICMProfile
#undef SetICMProfile
#undef EnumICMProfiles

#define BaseOf_GDI(name, idt) name : public Native::GObjectBase<name, idt>

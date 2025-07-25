/***********************************************************************************
**
** FileManager.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef FILEMANAGER_H
#define FILEMANAGER_H
//----------------------------------------------------------------------------------
class CUopBlockHeader
{
public:
    uint64 Offset = 0;
    //uint HeaderSize = 0;
    uint CompressedSize = 0;
    uint DecompressedSize = 0;
    //uint64 Hash = 0;
    //uint Unknown = 0;
    //ushort Flags = 0;

    CUopBlockHeader() {}
    CUopBlockHeader(
        uint64 offset,
        int headerSize,
        int compresseSize,
        int decompressedSize,
        uint64 Hash,
        int unknown,
        ushort flags)
        : Offset(offset)
        , CompressedSize(compresseSize)
        , DecompressedSize(decompressedSize)
    {
    }
    ~CUopBlockHeader() {}
};
//----------------------------------------------------------------------------------
class CUopMappedFile : public WISP_FILE::CMappedFile
{
public:
    std::unordered_map<uint64, CUopBlockHeader> m_Map;

public:
    CUopMappedFile();
    virtual ~CUopMappedFile();

    void Add(uint64 hash, const CUopBlockHeader &item);

    CUopBlockHeader *GetBlock(uint64 hash);

    UCHAR_LIST GetData(const CUopBlockHeader &block);
};
//----------------------------------------------------------------------------------
class CFileManager : public WISP_DATASTREAM::CDataReader
{
public:
    bool UseVerdata = false;
    bool UseUOPGumps = false;
    int UnicodeFontsCount = 0;

    CFileManager();
    virtual ~CFileManager();

    AutoResetEvent m_AutoResetEvent;

    //!Адреса файлов в памяти
    WISP_FILE::CMappedFile m_AnimIdx[MAX_MAPS_COUNT];
    WISP_FILE::CMappedFile m_ArtIdx;
    WISP_FILE::CMappedFile m_GumpIdx;
    WISP_FILE::CMappedFile m_LightIdx;
    WISP_FILE::CMappedFile m_MultiIdx;
    WISP_FILE::CMappedFile m_SkillsIdx;
    WISP_FILE::CMappedFile m_SoundIdx;
    WISP_FILE::CMappedFile m_StaticIdx[MAX_MAPS_COUNT];
    WISP_FILE::CMappedFile m_TextureIdx;

    std::fstream m_AnimMul[MAX_MAPS_COUNT];
    WISP_FILE::CMappedFile m_AnimdataMul;
    WISP_FILE::CMappedFile m_ArtMul;
    WISP_FILE::CMappedFile m_HuesMul;
    WISP_FILE::CMappedFile m_GumpMul;
    WISP_FILE::CMappedFile m_LightMul;
    WISP_FILE::CMappedFile m_MapMul[MAX_MAPS_COUNT];
    WISP_FILE::CMappedFile m_MultiMul;
    WISP_FILE::CMappedFile m_RadarcolMul;
    WISP_FILE::CMappedFile m_SkillsMul;
    WISP_FILE::CMappedFile m_SoundMul;
    WISP_FILE::CMappedFile m_StaticMul[MAX_MAPS_COUNT];
    WISP_FILE::CMappedFile m_TextureMul;
    WISP_FILE::CMappedFile m_TiledataMul;
    WISP_FILE::CMappedFile m_UnifontMul[20];
    WISP_FILE::CMappedFile m_VerdataMul;
    WISP_FILE::CMappedFile m_FacetMul[MAX_MAPS_COUNT];

    WISP_FILE::CMappedFile m_MultiMap;
    WISP_FILE::CMappedFile m_SpeechMul;
    WISP_FILE::CMappedFile m_LangcodeIff;

    //UOP
    CUopMappedFile m_ArtLegacyMUL;
    CUopMappedFile m_GumpartLegacyMUL;
    CUopMappedFile m_SoundLegacyMUL;
    CUopMappedFile m_Tileart;
    CUopMappedFile m_MainMisc;
    CUopMappedFile m_MapUOP[MAX_MAPS_COUNT];
    CUopMappedFile m_MapXUOP[MAX_MAPS_COUNT];
    CUopMappedFile m_AnimationSequence;
    CUopMappedFile m_MultiCollection;

    //Map patches
    WISP_FILE::CMappedFile m_MapDifl[MAX_MAPS_COUNT];
    WISP_FILE::CMappedFile m_MapDif[MAX_MAPS_COUNT];

    WISP_FILE::CMappedFile m_StaDifl[MAX_MAPS_COUNT];
    WISP_FILE::CMappedFile m_StaDifi[MAX_MAPS_COUNT];
    WISP_FILE::CMappedFile m_StaDif[MAX_MAPS_COUNT];

    bool Load();
    bool LoadWithUOP();
    void Unload();
    void TryReadUOPAnimations();

    //Чтение сжатых данных с кадрами из УОП аним файла.
    static char *ReadUOPDataFromFileStream(UOPAnimationData &animData);

    void
    ReadAnimMulDataFromFileStream(vector<char> &animData, CTextureAnimationDirection &direction);

    //Разжатие данных с кадрами из УОП аним файла.
    static bool
    DecompressUOPFileData(UOPAnimationData &animData, UCHAR_LIST &decLayoutData, char *buf);

    void SendFilesInfo();

    bool IsMulFileOpen(int idx) const;

private:
    void ReadTask();
    static bool FileExists(const os_path &filename);

    static bool TryOpenFileStream(std::fstream &fileStream, const os_path &filePath);

    bool LoadUOPFile(CUopMappedFile &file, const char *fileName);
};
//---------------------------------------------------------------------------
extern CFileManager g_FileManager;
//---------------------------------------------------------------------------
#endif
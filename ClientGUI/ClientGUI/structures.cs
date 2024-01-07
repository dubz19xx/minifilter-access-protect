using System.Runtime.InteropServices;
using System.Windows.Media.Imaging;

[StructLayout(LayoutKind.Sequential)]
public struct ProtectionParameters
{
    [MarshalAs(UnmanagedType.U1)]
    public bool ReadProtect;
    [MarshalAs(UnmanagedType.U1)]
    public bool WriteProtect;
    [MarshalAs(UnmanagedType.U1)]
    public bool DeleteProtect;
};

[StructLayout(LayoutKind.Sequential)]
public struct AccessLevel
{
    [MarshalAs(UnmanagedType.U1)]
    public bool UsermodeAccess;
    [MarshalAs(UnmanagedType.U1)]
    public bool AdminAccess;
    [MarshalAs(UnmanagedType.U1)]
    public bool KernelAccess;
};

[StructLayout(LayoutKind.Sequential)]
public struct ProtectMessage
{
    [MarshalAs(UnmanagedType.ByValArray, SizeConst =261)]
    public byte[] FilePath;

    public ProtectionParameters protect;

    public AccessLevel access;

//    public byte[] FilePath;

    public ProtectMessage()
    {
        FilePath=new byte[261];
        protect.ReadProtect = false; protect.WriteProtect= false; protect.DeleteProtect= false;
        access.KernelAccess = false; access.UsermodeAccess = false; access.AdminAccess = false;
    }
};

class FileDetails
{
    public string Filename { get; set; }
    public string rp { get; set; }
    public string wp { get; set; }
    public string dp { get; set; }
}


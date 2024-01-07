//using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Forms;


namespace ClientGUI
{
    
    public partial class MainWindow : Window
    {
        string redcross_path = (new BitmapImage(new Uri(@"/Images/red_cross.jpg", UriKind.Relative))).UriSource.ToString();
        string greentick_path = (new BitmapImage(new Uri(@"/Images/green_tick.jpg", UriKind.Relative))).UriSource.ToString();

        const string DllPath = "ClientDll.dll";
        //const string DllPath = "D:\\Projects\\DumbProtect\\ClientDll\\x64\\Debug\\ClientDll.dll";

        [DllImport(DllPath, CallingConvention =CallingConvention.Cdecl)]
        public static extern IntPtr GetCallback();

        [DllImport(DllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void SendToFilter(IntPtr obj, ProtectMessage pro_msg);

        [DllImport(DllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern int ConnectToFilter(IntPtr obj);

        IntPtr dp_user;
        ProtectMessage prm = new ProtectMessage();
        FileDetails fd = new FileDetails();

        public MainWindow()
        {
            InitializeComponent();            
        }

        ScrollViewer sv1, sv2;

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            sv1 = VisualTreeHelper.GetChild(VisualTreeHelper.GetChild(this.loglist, 0), 0) as ScrollViewer;
            sv2 = VisualTreeHelper.GetChild(VisualTreeHelper.GetChild(this.logpro, 0), 0) as ScrollViewer;
            sv1.ScrollChanged += new ScrollChangedEventHandler(ScrollChanged);
            sv2.ScrollChanged += new ScrollChangedEventHandler(ScrollChanged);

            dp_user = GetCallback();
            ConnectToFilter(dp_user);


            fd.rp = redcross_path;
            fd.wp = redcross_path;
            fd.dp = redcross_path;

        }


        private void ScrollChanged(object sender, ScrollChangedEventArgs e)
        {
            sv1.ScrollToVerticalOffset(sv2.VerticalOffset);
        }

    }
}

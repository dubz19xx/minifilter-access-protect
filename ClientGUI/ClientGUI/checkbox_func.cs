using System;
using System.Diagnostics.Contracts;
using System.IO;
using System.Reflection;
using System.Windows;
using System.Windows.Media.Imaging;

namespace ClientGUI
{
    public partial class MainWindow : Window
    {

        private void readbox_Checked(object sender, RoutedEventArgs e)
        {
            fd.rp = greentick_path;
            prm.protect.ReadProtect = true;
        }

        private void readbox_Unchecked(object sender, RoutedEventArgs e)
        {
            fd.rp = redcross_path;
            prm.protect.ReadProtect = false;
        }

        private void writebox_Checked(object sender, RoutedEventArgs e)
        {
            fd.wp = greentick_path;
            prm.protect.WriteProtect = true;
        }

        private void writebox_Unchecked(object sender, RoutedEventArgs e)
        {
            fd.wp = redcross_path;
            prm.protect.WriteProtect = false;
        }



        private void deletebox_Checked(object sender, RoutedEventArgs e)
        {
            fd.dp = greentick_path;
            prm.protect.DeleteProtect = true;
        }

        private void deletebox_Unchecked(object sender, RoutedEventArgs e)
        {
            fd.dp = redcross_path;
            prm.protect.DeleteProtect = false;
        }

        private void usermode_button_Checked(object sender, RoutedEventArgs e)
        {
            prm.access.UsermodeAccess = true;   
        }

        private void usermode_button_Unchecked(object sender, RoutedEventArgs e)
        {
            prm.access.UsermodeAccess = false;
        }

        private void admin_button_Checked(object sender, RoutedEventArgs e)
        {
            prm.access.AdminAccess = true;
        }

        private void admin_button_Unchecked(object sender, RoutedEventArgs e)
        {
            prm.access.AdminAccess = false;
        }

        private void kernel_button_Checked(object sender, RoutedEventArgs e)
        {
            prm.access.KernelAccess = true;
        }

        private void kernel_button_Unchecked(object sender, RoutedEventArgs e)
        {
            prm.access.KernelAccess= false;
        }

    }
}
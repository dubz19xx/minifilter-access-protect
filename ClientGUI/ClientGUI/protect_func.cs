using System;
using System.Diagnostics.CodeAnalysis;
using System.Runtime.InteropServices;
using System.Windows;

namespace ClientGUI
{
    public partial class MainWindow : Window
    {

        private void startop_Click(object sender, RoutedEventArgs e)
        {
            
            SendToFilter(dp_user, prm);

            loglist.Items.Add(fd);
            logpro.Items.Add(fd);
        }


    }
}
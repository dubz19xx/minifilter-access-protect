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
        private void filechooseButton_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog
            {
                CheckFileExists = true
            };

            if (ofd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                selectedfileName.Text = ofd.FileName;
            }

            fd.Filename = selectedfileName.Text;
            for(int i=0; i<ofd.FileName.Length; i++)
            {
                prm.FilePath[i] = (byte)ofd.FileName[i];
            }
//            byte[] fuck = Encoding.Unicode.GetBytes(ofd.FileName);
 //           Array.Copy(fuck, prm.FilePath, fuck.Length);
//            prm.FilePath = somin;
        }

    }
}
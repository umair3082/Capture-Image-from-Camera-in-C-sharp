using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ccO2urMNHFLXGD;
using System.Data.SqlClient;
using DevComponents.DotNetBar;
using DevComponents.DotNetBar.Controls;
using DevComponents.DotNetBar.SuperGrid;
using CrystalDecisions.CrystalReports.Engine;
using System.IO;
using AForge.Video;
using AForge.Video.DirectShow;
using System.Drawing.Imaging;

namespace gym_management_system
{

 public partial class Form1 : DevComponents.DotNetBar.Metro.MetroForm
    {
    
    public Form1()
        {
            InitializeComponent();
            #region For image capture

            CaptureDevice = new FilterInfoCollection(FilterCategory.VideoInputDevice);
            foreach (FilterInfo Device in CaptureDevice)
            {
                comboBox1.Items.Add(Device.Name);

            }
            // comboBox1.SelectedIndex = 0;
            FinalFrame = new VideoCaptureDevice();
            #endregion
            
        }
     #region Capture Var

        Bitmap video;
        bool onOff = false;
        int a = 5;
        Graphics g;
        private FilterInfoCollection CaptureDevice;
        private VideoCaptureDevice FinalFrame;
        #endregion
     private void Btn_StartCameraClick(object sender, EventArgs e)
     {
     if (comboBox1.Text == "")
                    {
                        MessageBox.Show("No Camera is Selected From Combobox !");
                        comboBox1.Focus();
                        return;
                    }
                    ///////// Start Button 
                    FinalFrame = new VideoCaptureDevice(CaptureDevice[comboBox1.SelectedIndex].MonikerString);
                    FinalFrame.NewFrame += new NewFrameEventHandler(FinalFrame_NewFrame);
                    FinalFrame.Start();
     
     }
     
     private void Btn_CaptureImageClick(object sender, EventArgs e)
     {
        if (comboBox1.Text == "")
                    {
                        MessageBox.Show("No Camera is Selected From Combobox !");
                        comboBox1.Focus();
                        return;
                    }
                    if (FinalFrame.IsRunning == true)
                    {
                        FinalFrame.Stop();
                    }
     }
     
     
     private void Btn_RemoveImageClick(object sender, EventArgs e)
     {
         pictureBox1.Image = null;
                    pictureBox1.Image = pictureBox1.InitialImage;
     }
      private void FinalFrame_NewFrame(object sender, NewFrameEventArgs eventArgs)
        {
            video = (Bitmap)eventArgs.Frame.Clone();
            Bitmap video2 = (Bitmap)eventArgs.Frame.Clone();
            // pictureBox1.Image = (Bitmap)eventArgs.Frame.Clone();
            if (onOff == true)
            {
                g = Graphics.FromImage(video2);
                g.DrawString(a.ToString(), new Font("Arial", 20), new SolidBrush(Color.White), new PointF(2, 2));
                g.Dispose();

            }
            pictureBox1.Image = video2;
        }
     
    }

}

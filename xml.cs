using System;
using System.Xml;

namespace ConsoleApplication4
{
    internal class Program
    {
        private static void Main()
        {
            const string xmlStr = @"<request type=""sync"" key=""1BF500B4158DBF04BA3045ABB38EAF0F"">
                                <host prod=""E10"" ver=""1.0.0.0"" ip=""192.168.11.17"" id=""E10_5.0_ZH1"" lang=""zh_CN"" timestamp=""20170719170824970"" acct=""dcms"" />
                                <service prod=""MES"" name=""lot.create"" />
                                <payload>
                                    <param key=""std_data"" type=""xml"">
                                        <data_request>
                                            <datainfo>
                                                <parameter key=""lot_data"" type=""data"">
                                                    <data name=""W304_DISPATCH_LIST"" cnt=""3"" tt_cnt=""0"" page=""0"" tt_page=""0"">
                                                        <row seq=""1"">
                                                            <field name=""disp_no"" type=""string"">5X11-170716001</field>
                                                            <field name=""disp_seq"" type=""numeric"">1</field>
                                                            <field name=""wo_no"" type=""string"">5101-17060800003</field>
                                                            <field name=""qty"" type=""numeric"">1890.000000</field>
                                                            <field name=""dpm_lot_no"" type=""string""/>
                                                            <field name=""workstation_no"" type=""string"">106</field>
                                                            <field name=""so_no"" type=""string"">GA-1707007-9-1</field>
                                                            <field name=""plan_start_date"" type=""date"">19000101000000000</field>
                                                            <field name=""plan_finish_date"" type=""date"">19000101000000000</field>
                                                        </row>
                                                        <row seq=""2"">
                                                            <field name=""disp_no"" type=""string"">5X11-170716001</field>
                                                            <field name=""disp_seq"" type=""numeric"">2</field>
                                                            <field name=""wo_no"" type=""string"">5101-17042200630</field>
                                                            <field name=""qty"" type=""numeric"">528.000000</field>
                                                            <field name=""dpm_lot_no"" type=""string""/>
                                                            <field name=""workstation_no"" type=""string"">106</field>
                                                            <field name=""so_no"" type=""string"">GA-1705002-2-1</field>
                                                            <field name=""plan_start_date"" type=""date"">19000101000000000</field>
                                                            <field name=""plan_finish_date"" type=""date"">19000101000000000</field>
                                                        </row>
                                                        <row seq=""3"">
                                                            <field name=""disp_no"" type=""string"">5X11-170716001</field>
                                                            <field name=""disp_seq"" type=""numeric"">3</field>
                                                            <field name=""wo_no"" type=""string"">5101-17050900672</field>
                                                            <field name=""qty"" type=""numeric"">396.000000</field>
                                                            <field name=""dpm_lot_no"" type=""string""/>
                                                            <field name=""workstation_no"" type=""string"">106</field>
                                                            <field name=""so_no"" type=""string"">GA-1705022-1-1</field>
                                                            <field name=""plan_start_date"" type=""date"">19000101000000000</field>
                                                            <field name=""plan_finish_date"" type=""date"">19000101000000000</field>
                                                        </row>
                                                    </data>
                                                </parameter>
                                            </datainfo>
                                        </data_request>
                                    </param>
                                </payload>
                            </request>";

            var doc = new XmlDocument();
            doc.LoadXml(xmlStr);

            var rowNoteList = doc.SelectNodes("/request/payload/param/data_request/datainfo/parameter/data/row");


            if (rowNoteList != null)
            {
                foreach (XmlNode rowNode in rowNoteList)
                {
                    var fieldNodeList = rowNode.ChildNodes;
                    foreach (XmlNode courseNode in fieldNodeList)
                    {
                        if (courseNode.Attributes != null)
                        {
                            Console.Write(courseNode.Attributes["name"].Value);
                            Console.Write("\t");
                            Console.Write(courseNode.Attributes["type"].Value);
                        }
                        Console.Write("\t");
                        Console.WriteLine(courseNode.InnerText.Trim());
                    }
                    Console.Write("\n");
                }
            }

            Console.Write("\r\nPress any key to continue....");
            Console.Read();

        }
    }
}